// Constructs a scaling matrix:
XMMATRIX XM_CALLCONV XMMatrixScaling(
    float ScaleX,
    float ScaleY,
    float ScaleZ);                      // Scaling factors

// Constructs a scaling matrix from components in vector:
XMMATRIX XM_CALLCONV XMMatrixScalingFromVector(
    FXMVECTOR Scale);                   // Scaling factors (sx, sy, sz)

// Constructs a x-axis rotation matrix Rx:
XMMATRIX XM_CALLCONV XMMatrixRotationX(
    float Angle);                       // Clockwise angle 'theta' to rotate

// Constructs a y-axis rotation matrix Ry:
XMMATRIX XM_CALLCONV XMMatrixRotationY(
    float Angle);                       // Clockwise angle 'theta' to rotate

// Constructs a z-axis rotation matrix Rz:
XMMATRIX XM_CALLCONV XMMatrixRotationZ(
    float Angle);                       // Clockwise angle 'theta' to rotate

// Constructs an arbitrary axis rotation matrix Rn:
XMMATRIX XM_CALLCONV XMMatrixRotationAxis(
    FXMVECTOR Axis,                     // Axis n to rotate about
    float Angle);                       // Clockwise angle 'theta' to rotate

// Constructs a translation matrix:
XMMATRIX XM_CALLCONV XMMatrixTranslation(
        float OffsetX,
        float OffsetY,
        float OffsetZ);                 // Translation factors

// Constructs a translation matrix from components in a vector:
XMMATRIX XM_CALLCONV XMMatrixTranslationFromVector(
    FXMVECTOR Offset);                  // Translation factors (tx, ty, tz)

// Computes the vector-matrix product vM where vw = 1 for transforming points:
XMVECTOR XM_CALLCONV XMVector3TransformCoord(
    FXMVECTOR V,                        // Input v
    CXMMATRIX M);                       // Input M

// Computes the vector-matrix product vM where vw = 0 for transforming vectors:
XMVECTOR XM_CALLCONV XMVector3TransformNormal(
    FXMVECTOR V,                        // Input v
    CXMMATRIX M);                       // Input M

/////////////////////////////////////////////////////////////////////////////

// Constructs a scaling matrix:
XMMATRIX XM_CALLCONV XMMatrixScaling(
    float ScaleX,
    float ScaleY,
    float ScaleZ);                      // Scaling factors

// Constructs a scaling matrix from components in vector:
XMMATRIX XM_CALLCONV XMMatrixScalingFromVector(
    FXMVECTOR Scale);                   // Scaling factors (sx, sy, sz)

// Constructs a x-axis rotation matrix Rx:
XMMATRIX XM_CALLCONV XMMatrixRotationX(
    float Angle);                       // Clockwise angle theta to rotate

// Constructs a y-axis rotation matrix Ry:
XMMATRIX XM_CALLCONV XMMatrixRotationY(
    float Angle);                      // Clockwise angle theta to rotate

// Constructs a z-axis rotation matrix Rz:
XMMATRIX XM_CALLCONV XMMatrixRotationZ(
    float Angle);                      // Clockwise angle theta to rotate

// Constructs an arbitrary axis rotation matrix Rn:
XMMATRIX XM_CALLCONV XMMatrixRotationAxis(
    FXMVECTOR Axis,                    // Axis n to rotate about
    float Angle);                      // Clockwise angle theta to rotate

// Constructs a translation matrix:
XMMATRIX XM_CALLCONV XMMatrixTranslation(
    float OffsetX,
    float OffsetY,
    float OffsetZ);                    // Translation factors

// Constructs a translation matrix from components in a vector:
XMMATRIX XM_CALLCONV XMMatrixTranslationFromVector(
    FXMVECTOR Offset);                 // Translation factors (tx, ty, tz)

// Computes the vector-matrix product vM where vw = 1 for transforming points:
XMVECTOR XM_CALLCONV XMVector3TransformCoord(
    FXMVECTOR V,                       // Input v
    CXMMATRIX M);                      // Input M

// Computes the vector-matrix product vM where vw = 0 for transforming vectors:
XMVECTOR XM_CALLCONV XMVector3TransformNormal(
    FXMVECTOR V,                       // Input v
    CXMMATRIX M);                      // Input M

/////////////////////////////////////////////////////////////////////////////