struct XMFLOAT2 {
    float x;
    float y;

    XMFLOAT2() {}

    XMFLOAT2(float _x, float _y) : x(_x), y(_y) {}

    explicit XMFLOAT2(_In_reads_(2) const float *pArray) :
    x(pArray[0]), y(pArray[1]) {}

    XMFLOAT2& operator= (const XMFLOAT2& Float2) {
        x = Float1.x; y = Float2.y; return *this;
    }
};

struct XMFLOAT3 {
    float x;
    float y;
    float z;

    XMFLOAT3() {}

    XMFLOAT3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    explicit XMFLOAT3(_In_reads_(3) const float *pArray) :
    x(pArray[0]), y(pArray[1]), z(pArray[2]) {}

    XMFLOAT3& operator= (const XMFLOAT3& Float {
        x = Float3.x; y = Float3.y; z = Float3.z; return *this;
    }
};

struct XMFLOAT4 {
    float x;
    float y;
    float z;
    float w;

    XMFLOAT4() {}

    XMFLOAT4(float _x, float _y, float _z, float _w) :
    x(_x), y(_y), z(_z), w(_w) {}

    explicit XMFLOAT4(_In_reads_(4) const float *pArray) :
    x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}

    XMFLOAT4& operator= (const XMFLOAT4& Float4){
        x = Float4.x; y = Float4.y; z = Float4.z; w = Float4.w; return *this;
    }
};

/////////////////////////////////////////////////////////////////////////////

// Loads XMFLOAT2 into XMVECTOR
XMVECTOR XM_CALLCONV XMLoadFloat2(const XMFLOAT2 *pSource);

// Loads XMFLOAT3 into XMVECTOR
XMVECTOR XM_CALLCONV XMLoadFloat3(const XMFLOAT3 *pSource);

// Loads XMFLOAT4 into XMVECTOR
XMVECTOR XM_CALLCONV XMLoadFloat4(const XMFLOAT4 *pSource);

/////////////////////////////////////////////////////////////////////////////

// Loads XMVECTOR into XMFLOAT2
void XM_CALLCONV XMStoreFloat2(XMFLOAT2 *pDestination, FXMVECTOR V);

// Loads XMVECTOR into XMFLOAT3
void XM_CALLCONV XMStoreFloat3(XMFLOAT3 *pDestination, FXMVECTOR V);

// Loads XMVECTOR into XMFLOAT4
void XM_CALLCONV XMStoreFloat4(XMFLOAT4 *pDestination, FXMVECTOR V);

/////////////////////////////////////////////////////////////////////////////

float XM_CALLCONV XMVectorGetX(FXMVECTOR V);
float XM_CALLCONV XMVectorGetY(FXMVECTOR V);
float XM_CALLCONV XMVectorGetZ(FXMVECTOR V);
float XM_CALLCONV XMVectorGetW(FXMVECTOR V);
XMVECTOR XM_CALLCONV XMVectorSetX(FXMVECTOR V, float x);
XMVECTOR XM_CALLCONV XMVectorSetY(FXMVECTOR V, float y);
XMVECTOR XM_CALLCONV XMVectorSetZ(FXMVECTOR V, float z);
XMVECTOR XM_CALLCONV XMVectorSetW(FXMVECTOR V, float w);

/////////////////////////////////////////////////////////////////////////////

// 32-bit Windows __fastcall passes first 3 XMVECTOR arguments
// via registers, the remaining on the stack.
typedef const XMVECTOR FXMVECTOR;
typedef const XMVECTOR& GXMVECTOR;
typedef const XMVECTOR& HXMVECTOR;
typedef const XMVECTOR& CXMVECTOR;

// 32-bit Windows __vectorcall passes first 6 XMVECTOR arguments
// via registers, the remaining on the stack.
typedef const XMVECTOR FXMVECTOR;
typedef const XMVECTOR GXMVECTOR;
typedef const XMVECTOR HXMVECTOR;
typedef const XMVECTOR& CXMVECTOR;

/////////////////////////////////////////////////////////////////////////////

inline XMMATRIX XM_CALLCONV XMMatrixTransformation(
    FXMVECTOR ScalingOrigin,
    FXMVECTOR ScalingOrientationQuaternion,
    FXMVECTOR Scaling,
    GXMVECTOR RotationOrigin,
    HXMVECTOR RotationQuaternion,
    HXMVECTOR Translation);

/////////////////////////////////////////////////////////////////////////////

inline XMMATRIX XM_CALLCONV XMMatrixTransformation2D(
    FXMVECTOR ScalingOrigin,
    float ScalingOrientation,
    FXMVECTOR Scaling,
    FXMVECTOR RotationOrigin,
    float Rotation,
    GXMVECTOR Translation);

/////////////////////////////////////////////////////////////////////////////

static const XMVECTORF32 g_vHalfVector = { 0.5f, 0.5f, 0.5f, 0.5f };
static const XMVECTORF32 g_vZero = { 0.0f, 0.0f, 0.0f, 0.0f };

XMVECTORF32 vRightTop = {
    vViewFrust.RightSlope,
    vViewFrust.TopSlope,
    1.0f,1.0f
};

XMVECTORF32 vLeftBottom = {
    vViewFrust.LeftSlope,
    vViewFrust.BottomSlope,
    1.0f,1.0f
};

/////////////////////////////////////////////////////////////////////////////

 // Conversion types for constants
__declspec(align(16)) struct XMVECTORF32 {
    union {
        float f[4];
        XMVECTOR v;
    };
    inline operator XMVECTOR() const { return v; }
    inline operator const float*() const { return f; }
    #if !defined(_XM_NO_INTRINSICS_) && defined(_XM_SSE_INTRINSICS_)
        inline operator __m128i() const { return _mm_castps_si128(v); }
        inline operator __m128d() const { return _mm_castps_pd(v); }
    #endif
};



/////////////////////////////////////////////////////////////////////////////

static const XMVECTORU32 vGrabY={0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000};



/////////////////////////////////////////////////////////////////////////////

XMVECTOR XM_CALLCONV operator+ (FXMVECTOR V);
XMVECTOR XM_CALLCONV operator- (FXMVECTOR V);
XMVECTOR& XM_CALLCONV operator+= (XMVECTOR& V1, FXMVECTOR V2);
XMVECTOR& XM_CALLCONV operator-= (XMVECTOR& V1, FXMVECTOR V2);
XMVECTOR& XM_CALLCONV operator*= (XMVECTOR& V1, FXMVECTOR V2);
XMVECTOR& XM_CALLCONV operator/= (XMVECTOR& V1, FXMVECTOR V2);
XMVECTOR& operator*= (XMVECTOR& V, float S);
XMVECTOR& operator/= (XMVECTOR& V, float S);
XMVECTOR XM_CALLCONV operator+ (FXMVECTOR V1, FXMVECTOR V2);
XMVECTOR XM_CALLCONV operator- (FXMVECTOR V1, FXMVECTOR V2);
XMVECTOR XM_CALLCONV operator* (FXMVECTOR V1, FXMVECTOR V2);
XMVECTOR XM_CALLCONV operator/ (FXMVECTOR V1, FXMVECTOR V2);
XMVECTOR XM_CALLCONV operator* (FXMVECTOR V, float S);
XMVECTOR XM_CALLCONV operator* (float S, FXMVECTOR V);
XMVECTOR XM_CALLCONV operator/ (FXMVECTOR V, float S);

/////////////////////////////////////////////////////////////////////////////

const float XM_PI = 3.141592654f;
const float XM_2PI = 6.283185307f;
const float XM_1DIVPI = 0.318309886f;
const float XM_1DIV2PI = 0.159154943f;
const float XM_PIDIV2 = 1.570796327f;
const float XM_PIDIV4 = 0.785398163f;

/////////////////////////////////////////////////////////////////////////////

inline float XMConvertToRadians(float fDegrees) {
    return fDegrees * (XM_PI / 180.0f);
}

inline float XMConvertToDegrees(float fRadians){
    return fRadians * (180.0f / XM_PI);
}

/////////////////////////////////////////////////////////////////////////////

template<class T> inline T XMMin(T a, T b) { return (a < b) ? a : b; }
template<class T> inline T XMMax(T a, T b) { return (a > b) ? a : b; }

/////////////////////////////////////////////////////////////////////////////

// Returns the zero vector 0
XMVECTOR XM_CALLCONV XMVectorZero();
// Returns the vector (1, 1, 1, 1)
XMVECTOR XM_CALLCONV XMVectorSplatOne();
// Returns the vector (x, y, z, w)
XMVECTOR XM_CALLCONV XMVectorSet(float x, float y, float z, float w);
// Returns the vector (s, s, s, s)
XMVECTOR XM_CALLCONV XMVectorReplicate(float Value);
// Returns the vector (vx,vx, vx,vx)
XMVECTOR XM_CALLCONV XMVectorSplatX(FXMVECTOR V);
// Returns the vector (vy,vy, vy,vy)
XMVECTOR XM_CALLCONV XMVectorSplatY(FXMVECTOR V);
// Returns the vector (vz, vz, vz, vz)
XMVECTOR XM_CALLCONV XMVectorSplatZ(FXMVECTOR V);

/////////////////////////////////////////////////////////////////////////////

#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// Overload the "<<" operators so that we can use cout to
// output XMVECTOR objects.
ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) {
    XMFLOAT3 dest;
    XMStoreFloat3(&dest, v);
    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
    return os;
}

int main() {
    cout.setf(ios_base::boolalpha);
    // Check support for SSE2 (Pentium4, AMD K8, and above).
    if (!XMVerifyCPUSupport()) {
        cout << "directx math not supported" << endl;
        return 0;
    }

    XMVECTOR p = XMVectorZero();
    XMVECTOR q = XMVectorSplatOne();
    XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
    XMVECTOR v = XMVectorReplicate(-2.0f);
    XMVECTOR w = XMVectorSplatZ(u);

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "u = " << u << endl;
    cout << "v = " << v << endl;
    cout << "w = " << w << endl;

    return 0;
}


/////////////////////////////////////////////////////////////////////////////

XMVECTOR XM_CALLCONV XMVector3Length(          // Returns ||v||
    FXMVECTOR V);                              // Input v

XMVECTOR XM_CALLCONV XMVector3LengthSq(        // Returns ||v||^2
    FXMVECTOR V);                              // Input v

XMVECTOR XM_CALLCONV XMVector3Dot(             // Returns v1 . v2
    FXMVECTOR V1,                              // Input v1
    FXMVECTOR V2);                             // Input v2

XMVECTOR XM_CALLCONV XMVector3Cross(           // Returns v1 x v2
    FXMVECTOR V1,                              // Input v1
    FXMVECTOR V2);                             // Input v2

XMVECTOR XM_CALLCONV XMVector3Normalize(       // Returns v/||v||
    FXMVECTOR V);                              // Input v

XMVECTOR XM_CALLCONV XMVector3Orthogonal(      // Returns a vector orthogonal to v
    FXMVECTOR V);                              // Input v

XMVECTOR XM_CALLCONV
XMVector3AngleBetweenVectors(                  // Returns the angle between v1 & v2
    FXMVECTOR V1,                              // Input v1
    FXMVECTOR V2);                             // Input v2

void XM_CALLCONV XMVector3ComponentsFromNormal(
    XMVECTOR* pParallel,                       // Returns projn(v)
    XMVECTOR* pPerpendicular,                  // Returns perpn(v)
    FXMVECTOR V,                               // Input v
    FXMVECTOR Normal);                         // Input n

bool XM_CALLCONV XMVector3Equal(               // Returns v1 = v2
    FXMVECTOR V1,                              // Input v1
    FXMVECTOR V2);                             // Input v2

bool XM_CALLCONV XMVector3NotEqual(            // Returns v1 != v2
    FXMVECTOR V1,                              // Input v1
    FXMVECTOR V2);                             // Input v2

/////////////////////////////////////////////////////////////////////////////

#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// Overload the "<<" operators so that we can use cout to
// output XMVECTOR objects.
ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) {
    XMFLOAT3 dest;
    XMStoreFloat3(&dest, v);
    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
    return os;
}

int main() {
    cout.setf(ios_base::boolalpha);

    // Check support for SSE2 (Pentium4, AMD K8, and above).
    if (!XMVerifyCPUSupport()) {
        cout << "directx math not supported" << endl;
        return 0;
    }

    XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
    XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
    XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
    XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

    // Vector addition: XMVECTOR operator +
    XMVECTOR a = u + v;
    // Vector subtraction: XMVECTOR operator -
    XMVECTOR b = u - v;
    // Scalar multiplication: XMVECTOR operator *
    XMVECTOR c = 10.0f*u;
    // ||u||
    XMVECTOR L = XMVector3Length(u);
    // d = u / ||u||
    XMVECTOR d = XMVector3Normalize(u);
    // s = u dot v
    XMVECTOR s = XMVector3Dot(u, v);
    // e = u x v
    XMVECTOR e = XMVector3Cross(u, v);
    // Find proj_n(w) and perp_n(w)
    XMVECTOR projW;
    XMVECTOR perpW;
    XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

    // Does projW + perpW == w?
    bool equal = XMVector3Equal(projW + perpW, w) != 0;
    bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

    // The angle between projW and perpW should be 90 degrees.
    XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
    float angleRadians = XMVectorGetX(angleVec);
    float angleDegrees = XMConvertToDegrees(angleRadians);

    cout << "u             = " << u << endl;
    cout << "v             = " << v << endl;
    cout << "w             = " << w << endl;
    cout << "n             = " << n << endl;
    cout << "a = u + v     = " << a << endl;
    cout << "b = u - v     = " << b << endl;
    cout << "c = 10 * u    = " << c << endl;
    cout << "d = u / ||u|| = " << d << endl;
    cout << "e = u x v     = " << e << endl;
    cout << "L = ||u||     = " << L << endl;
    cout << "s = u.v       = " << s << endl;
    cout << "projW         = " << projW << endl;
    cout << "perpW         = " << perpW << endl;
    cout << "projW + perpW == w = " << equal << endl;
    cout << "projW + perpW != w = " << notEqual << endl;
    cout << "angle         = " << angleDegrees << endl;
    return 0;
}


/////////////////////////////////////////////////////////////////////////////

XMVECTOR XM_CALLCONV XMVector3LengthEst(       // Returns estimated ||v||
    FXMVECTOR V);                              // Input v
XMVECTOR XM_CALLCONV XMVector3NormalizeEst(    // Returns estimated v/||v||
    FXMVECTOR V);                              // Input v

/////////////////////////////////////////////////////////////////////////////

#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

int main()  {
    cout.precision(8);

    // Check support for SSE2 (Pentium4, AMD K8, and above).
    if (!XMVerifyCPUSupport()) {
        cout << "directx math not supported" << endl;
        return 0;
    }

    XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
    XMVECTOR n = XMVector3Normalize(u);

    float LU = XMVectorGetX(XMVector3Length(n));

    // Mathematically, the length should be 1. Is it numerically?
    cout << LU << endl;
    if (LU == 1.0f)
        cout << "Length 1" << endl;
    else
        cout << "Length not 1" << endl;

    // Raising 1 to any power should still be 1. Is it?
    float powLU = powf(LU, 1.0e6f);
    cout << "LU^(10^6) = " << powLU << endl;
}

/////////////////////////////////////////////////////////////////////////////

const float Epsilon = 0.001f;
bool Equals(float lhs, float rhs) {
    // Is the distance between lhs and rhs less than EPSILON?
    return fabs(lhs - rhs) < Epsilon ? true : false;
}

/////////////////////////////////////////////////////////////////////////////

// Returns
// abs(U.x – V.x) <= Epsilon.x &&
// abs(U.y – V.y) <= Epsilon.y &&
// abs(U.z – V.z) <= Epsilon.z
XMFINLINE bool XM_CALLCONV XMVector3NearEqual(
    FXMVECTOR U,
    FXMVECTOR V,
    FXMVECTOR Epsilon);

/////////////////////////////////////////////////////////////////////////////

XMVECTOR XM_CALLCONV XMVector3Length(FXMVECTOR V);
XMVECTOR XM_CALLCONV XMVector3LengthSq(FXMVECTOR V);
XMVECTOR XM_CALLCONV XMVector3Dot(FXMVECTOR V1, FXMVECTOR V2);
XMVECTOR XM_CALLCONV XMVector3Cross(FXMVECTOR V1, FXMVECTOR V2);
XMVECTOR XM_CALLCONV XMVector3Normalize(FXMVECTOR V);

/////////////////////////////////////////////////////////////////////////////

#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// Overload the "<<" operators so that we can use cout to
// output XMVECTOR objects.
ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) {
    XMFLOAT4 dest;
    XMStoreFloat4(&dest, v);
    os << "(" << dest.x << ", " << dest.y << ", "
    << dest.z << ", " << dest.w << ")";
    return os;
}

int main() {
    cout.setf(ios_base::boolalpha);

    // Check support for SSE2 (Pentium4, AMD K8, and above).
    if (!XMVerifyCPUSupport()) {
        cout << "directx math not supported" << endl;
        return 0;
    }

    XMVECTOR p = XMVectorSet(2.0f, 2.0f, 1.0f, 0.0f);
    XMVECTOR q = XMVectorSet(2.0f, -0.5f, 0.5f, 0.1f);
    XMVECTOR u = XMVectorSet(1.0f, 2.0f, 4.0f, 8.0f);
    XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 2.5f);
    XMVECTOR w = XMVectorSet(0.0f, XM_PIDIV4, XM_PIDIV2, XM_PI);

    cout << "XMVectorAbs(v) = " << XMVectorAbs(v) << endl;
    cout << "XMVectorCos(w) = " << XMVectorCos(w) << endl;
    cout << "XMVectorLog(u) = " << XMVectorLog(u) << endl;
    cout << "XMVectorExp(p) = " << XMVectorExp(p) << endl;
    cout << "XMVectorPow(u, p) = " << XMVectorPow(u, p) << endl;
    cout << "XMVectorSqrt(u) = " << XMVectorSqrt(u) << endl;
    cout << "XMVectorSwizzle(u, 2, 2, 1, 3) = " << XMVectorSwizzle(u, 2, 2, 1, 3) << endl;
    cout << "XMVectorSwizzle(u, 2, 1, 0, 3) = " << XMVectorSwizzle(u, 2, 1, 0, 3) << endl;
    cout << "XMVectorMultiply(u, v) = " << XMVectorMultiply(u, v) << endl;
    cout << "XMVectorSaturate(q) = " << XMVectorSaturate(q) << endl;
    cout << "XMVectorMin(p, v = " << XMVectorMin(p, v) << endl;
    cout << "XMVectorMax(p, v) = " << XMVectorMax(p, v) << endl;

    return 0;
}

/////////////////////////////////////////////////////////////////////////////


 +
 =

