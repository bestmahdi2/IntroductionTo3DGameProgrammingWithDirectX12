#if (defined(_M_IX86) || defined(_M_X64) || defined(_M_ARM)) && defined(_XM_NO_INTRINSICS_)
struct XMMATRIX
#else
__declspec(align(16)) struct XMMATRIX
#endif
{
    // Use 4 XMVECTORs to represent the matrix for SIMD.
    XMVECTOR r[4];
    
    XMMATRIX() {}
    
    // Initialize matrix by specifying 4 row vectors.
    XMMATRIX(FXMVECTOR R0, FXMVECTOR R1, FXMVECTOR R2, CXMVECTOR R3) { 
        r[0] = R0; r[1] = R1; r[2] = R2; r[3] = R3; 
    }
    
    // Initialize matrix by specifying 4 row vectors.
    XMMATRIX(float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33);
    
    // Pass array of sixteen floats to construct matrix.
    explicit XMMATRIX(_In_reads_(16) const float *pArray);
    
    XMMATRIX& operator= (const XMMATRIX& M) {
        r[0] = M.r[0]; r[1] = M.r[1]; r[2] = M.r[2]; r[3] = M.r[3];
        return *this; 
    }
    
    XMMATRIX operator+ () const { return *this; }
    XMMATRIX operator- () const;

    XMMATRIX& XM_CALLCONV operator+= (FXMMATRIX M);
    XMMATRIX& XM_CALLCONV operator-= (FXMMATRIX M);
    XMMATRIX& XM_CALLCONV operator*= (FXMMATRIX M);
    XMMATRIX& operator*= (float S);
    XMMATRIX& operator/= (float S);

    XMMATRIX XM_CALLCONV operator+ (FXMMATRIX M) const;
    XMMATRIX XM_CALLCONV operator- (FXMMATRIX M) const;
    XMMATRIX XM_CALLCONV operator* (FXMMATRIX M) const;
    XMMATRIX operator* (float S) const;
    XMMATRIX operator/ (float S) const;

    friend XMMATRIX XM_CALLCONV operator* (float S, FXMMATRIX M);
};

/////////////////////////////////////////////////////////////////////////////

XMMATRIX XM_CALLCONV XMMatrixSet(
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33);

/////////////////////////////////////////////////////////////////////////////

struct XMFLOAT4X4
{
    union {
        struct {float _11, _12, _13, _14;
                float _21, _22, _23, _24;
                float _31, _32, _33, _34;
                float _41, _42, _43, _44;};
        float m[4][4];
    };
    
    XMFLOAT4X4() {}
    XMFLOAT4X4(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33);
    explicit XMFLOAT4X4(_In_reads_(16) const float *pArray);
    
    float operator() (size_t Row, size_t Column) const {
        return m[Row] [Column]; 
    }
    float& operator() (size_t Row, size_t Column) {
        return m[Row] [Column];
    }
    
    XMFLOAT4X4& operator= (const XMFLOAT4X4& Float4x4);
};



/////////////////////////////////////////////////////////////////////////////

inline XMMATRIX XM_CALLCONV
XMLoadFloat4x4(const XMFLOAT4X4* pSource);

/////////////////////////////////////////////////////////////////////////////

inline void XM_CALLCONV
XMStoreFloat4x4(XMFLOAT4X4* pDestination, FXMMATRIX M);

/////////////////////////////////////////////////////////////////////////////

XMMATRIX XM_CALLCONV XMMatrixIdentity();    // Returns the identity matrix I

bool XM_CALLCONV XMMatrixIsIdentity(        // Returns true if M is the identity matrix
    FXMMATRIX M);                           // Input M

XMMATRIX XM_CALLCONV XMMatrixMultiply(      // Returns the matrix product AB
    FXMMATRIX A,                            // Input A
    CXMMATRIX B);                           // Input B

XMMATRIX XM_CALLCONV XMMatrixTranspose(     // Returns M^T
    FXMMATRIX M);                           // Input M

XMVECTOR XM_CALLCONV XMMatrixDeterminant(   // Returns (det M, det M, det M, det M)
    FXMMATRIX M);                           // Input M

XMMATRIX XM_CALLCONV XMMatrixInverse(       // Returns M^-1
    XMVECTOR* pDeterminant,                 // Input (det M, det M, det M, det M)
    FXMMATRIX M);                           // Input M

/////////////////////////////////////////////////////////////////////////////

// 32-bit Windows __fastcall passes first 3 XMVECTOR arguments
// via registers, the remaining on the stack.
typedef const XMMATRIX& FXMMATRIX;
typedef const XMMATRIX& CXMMATRIX;

// 32-bit Windows __vectorcall passes first 6 XMVECTOR arguments
// via registers, the remaining on the stack.
typedef const XMMATRIX FXMMATRIX;
typedef const XMMATRIX& CXMMATRIX;

/////////////////////////////////////////////////////////////////////////////

#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// Overload the "<<" operators so that we can use cout to
// output XMVECTOR and XMMATRIX objects.
ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v) {
    XMFLOAT4 dest;
    XMStoreFloat4(&dest, v);
    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " <<
    dest.w << ")";
    return os;
}

ostream& XM_CALLCONV operator << (ostream& os, FXMMATRIX m) {
    for (int i = 0; i < 4; ++i) {
        os << XMVectorGetX(m.r[i]) << "\t";
        os << XMVectorGetY(m.r[i]) << "\t";
        os << XMVectorGetZ(m.r[i]) << "\t";
        os << XMVectorGetW(m.r[i]);
        os << endl;
    }
    return os;
}

int main() {
    // Check support for SSE2 (Pentium4, AMD K8, and above).
    if (!XMVerifyCPUSupport()) {
        cout << "directx math not supported" << endl;
        return 0;
    }

    XMMATRIX A(1.0f, 0.0f, 0.0f, 0.0f,
               0.0f, 2.0f, 0.0f, 0.0f,
               0.0f, 0.0f, 4.0f, 0.0f,
               1.0f, 2.0f, 3.0f, 1.0f);

    XMMATRIX B = XMMatrixIdentity();

    XMMATRIX C = A * B;

    XMMATRIX D = XMMatrixTranspose(A);

    XMVECTOR det = XMMatrixDeterminant(A);
    XMMATRIX E = XMMatrixInverse(&det, A);

    XMMATRIX F = A * E;

    cout << "A = " << endl << A << endl;
    cout << "B = " << endl << B << endl;
    cout << "C = A*B = " << endl << C << endl;
    cout << "D = transpose(A) = " << endl << D << endl;
    cout << "det = determinant(A) = " << det << endl << endl;
    cout << "E = inverse(A) = " << endl << E << endl;
    cout << "F = A*E = " << endl << F << endl;

    return 0;
}

/////////////////////////////////////////////////////////////////////////////

XMMATRIX XM_CALLCONV XMMatrixIdentity();
    XMMATRIX XM_CALLCONV XMMatrixMultiply(FXMMATRIX A, CXMMATRIX B);
    XMMATRIX XM_CALLCONV XMMatrixTranspose(FXMMATRIX M);
    XMVECTOR XM_CALLCONV XMMatrixDeterminant(FXMMATRIX M);
    XMMATRIX XM_CALLCONV XMMatrixInverse(XMVECTOR* pDeterminant,
    FXMMATRIX M);

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
