#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned RedFBool32;

typedef struct RedFTypeHandleNode *                  RedFHandleNode;
typedef struct RedFTypeHandleCamera *                RedFHandleCamera;                // Derived from Node
typedef struct RedFTypeHandleFirstPersonCamera *     RedFHandleFirstPersonCamera;     // Derived from Camera
typedef struct RedFTypeHandleMesh *                  RedFHandleMesh;
typedef struct RedFTypeHandleImage *                 RedFHandleImage;
typedef struct RedFTypeHandleFbo *                   RedFHandleFbo;
typedef struct RedFTypeHandleLight *                 RedFHandleLight;                 // Derived from Node
typedef struct RedFTypeHandleMaterial *              RedFHandleMaterial;
typedef struct RedFTypeHandleShader *                RedFHandleShader;
typedef struct RedFTypeHandleManipulator *           RedFHandleManipulator;
typedef struct RedFTypeHandleAssimp *                RedFHandleAssimp;
typedef struct RedFTypeHandleEquiMap *               RedFHandleEquiMap;
typedef struct RedFTypeHandleImgui *                 RedFHandleImgui;
typedef struct RedFTypeHandleSoundPlayer *           RedFHandleSoundPlayer;
typedef struct RedFTypeHandleDirectory *             RedFHandleDirectory;
typedef struct RedFTypeHandleThread *                RedFHandleThread;
typedef struct RedFTypeHandleThreadChannel *         RedFHandleThreadChannel;
typedef struct RedFTypeHandleEventParametersKey *    RedFHandleEventParametersKey;
typedef struct RedFTypeHandleEventParametersMouse *  RedFHandleEventParametersMouse;
typedef struct RedFTypeHandleEventParametersResize * RedFHandleEventParametersResize;
typedef struct RedFTypeHandleEventParametersDrag *   RedFHandleEventParametersDrag;

typedef struct RedFEvents {
  void (*setup)           (void);
  void (*update)          (void);
  void (*draw)            (void);
  void (*exit)            (void);
  void (*keyPressed)      (RedFHandleEventParametersKey parameters);
  void (*keyReleased)     (RedFHandleEventParametersKey parameters);
  void (*mouseMoved)      (RedFHandleEventParametersMouse parameters);
  void (*mouseDragged)    (RedFHandleEventParametersMouse parameters);
  void (*mousePressed)    (RedFHandleEventParametersMouse parameters);
  void (*mouseReleased)   (RedFHandleEventParametersMouse parameters);
  void (*mouseScrolled)   (RedFHandleEventParametersMouse parameters);
  void (*mouseEntered)    (RedFHandleEventParametersMouse parameters);
  void (*mouseExited)     (RedFHandleEventParametersMouse parameters);
  void (*touchDown)       (void * parameters);
  void (*touchMoved)      (void * parameters);
  void (*touchUp)         (void * parameters);
  void (*touchDoubleTap)  (void * parameters);
  void (*touchCancelled)  (void * parameters);
  void (*windowResized)   (RedFHandleEventParametersResize parameters);
  void (*dragged)         (RedFHandleEventParametersDrag parameters);
  void (*messageReceived) (void * parameters);
} RedFEvents;

typedef struct RedFFboSettings {
  int        width;                      // Width of images attached to FBO
  int        height;                     // Height of images attached to FBO
  int        numColorbuffers;            // How many color buffers to create (max number is 8)
  int        colorFormats[8];            // Format of the color attachments for MRT
  RedFBool32 useDepth;                   // Whether to use depth buffer or not
  RedFBool32 useStencil;                 // Whether to use stencil buffer or not
  RedFBool32 depthStencilAsTexture;      // Use a texture instead of a renderbuffer for depth (useful to draw it or use it in a shader later)
  unsigned   textureTarget;              // GL_TEXTURE_2D or GL_TEXTURE_RECTANGLE_ARB
  int        internalformat;             // GL_RGBA, GL_RGBA16F_ARB, GL_RGBA32F_ARB, GL_LUMINANCE32F_ARB etc.
  int        depthStencilInternalFormat; // GL_DEPTH_COMPONENT(16/24/32)
  int        wrapModeHorizontal;         // GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER etc.
  int        wrapModeVertical;           // GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER etc.
  int        minFilter;                  // GL_NEAREST, GL_LINEAR etc.
  int        maxFilter;                  // GL_NEAREST, GL_LINEAR etc.
  int        numSamples;                 // Number of samples for multisampling (set 0 to disable)
} RedFFboSettings;

typedef struct RedFMaterialSettings {
  float        diffuse[4];     // Diffuse reflectance     (default is 0.8f, 0.8f, 0.8f, 1.0f)
  float        ambient[4];     // Ambient reflectance     (default is 0.2f, 0.2f, 0.2f, 1.0f)
  float        specular[4];    // Specular reflectance    (default is 0.0f, 0.0f, 0.0f, 1.0f)
  float        emissive[4];    // Emitted light intensity (default is 0.0f, 0.0f, 0.0f, 1.0f)
  float        shininess;      // Specular exponent       (default is 0.2f)
  const char * postFragment;
  const char * customUniforms;
} RedFMaterialSettings;

typedef enum RedFMatrixMode {
  REDF_MATRIX_MODE_MODEL_VIEW = 0,
  REDF_MATRIX_MODE_PROJECTION = 1,
} RedFMatrixMode;

typedef enum RedFMouseButton {
  REDF_MOUSE_BUTTON_1      = 0,
  REDF_MOUSE_BUTTON_2      = 1,
  REDF_MOUSE_BUTTON_3      = 2,
  REDF_MOUSE_BUTTON_4      = 3,
  REDF_MOUSE_BUTTON_5      = 4,
  REDF_MOUSE_BUTTON_6      = 5,
  REDF_MOUSE_BUTTON_7      = 6,
  REDF_MOUSE_BUTTON_8      = 7,
  REDF_MOUSE_BUTTON_LEFT   = REDF_MOUSE_BUTTON_1,
  REDF_MOUSE_BUTTON_MIDDLE = REDF_MOUSE_BUTTON_2,
  REDF_MOUSE_BUTTON_RIGHT  = REDF_MOUSE_BUTTON_3,
} RedFMouseButton;

typedef enum RedFKeyEventType {
  REDF_KEY_EVENT_TYPE_PRESSED  = 0,
  REDF_KEY_EVENT_TYPE_RELEASED = 1,
} RedFKeyEventType;

typedef enum RedFMouseEventType {
  REDF_MOUSE_EVENT_TYPE_PRESSED  = 0,
  REDF_MOUSE_EVENT_TYPE_MOVED    = 1,
  REDF_MOUSE_EVENT_TYPE_RELEASED = 2,
  REDF_MOUSE_EVENT_TYPE_DRAGGED  = 3,
  REDF_MOUSE_EVENT_TYPE_SCROLLED = 4,
  REDF_MOUSE_EVENT_TYPE_ENTERED  = 5,
  REDF_MOUSE_EVENT_TYPE_EXITED   = 6,
} RedFMouseEventType;

typedef enum RedFBlendMode {
  REDF_BLEND_MODE_DISABLED = 0,
  REDF_BLEND_MODE_ALPHA    = 1,
  REDF_BLEND_MODE_ADD      = 2,
  REDF_BLEND_MODE_SUBTRACT = 3,
  REDF_BLEND_MODE_MULTIPLY = 4,
  REDF_BLEND_MODE_SCREEN   = 5,
} RedFBlendMode;

typedef enum RedFPrimitiveMode {
  REDF_PRIMITIVE_MODE_TRIANGLES      = 0,
  REDF_PRIMITIVE_MODE_TRIANGLE_STRIP = 1,
  REDF_PRIMITIVE_MODE_TRIANGLE_FAN   = 2,
  REDF_PRIMITIVE_MODE_LINES          = 3,
  REDF_PRIMITIVE_MODE_LINE_STRIP     = 4,
  REDF_PRIMITIVE_MODE_LINE_LOOP      = 5,
  REDF_PRIMITIVE_MODE_POINTS         = 6,
} RedFPrimitiveMode;

typedef enum RedFPolyRenderMode {
  REDF_POLY_RENDER_MODE_POINTS    = 0,
  REDF_POLY_RENDER_MODE_WIREFRAME = 1,
  REDF_POLY_RENDER_MODE_FILL      = 2,
} RedFPolyRenderMode;

typedef enum RedFManipulatorType {
  REDF_MANIPULATOR_TYPE_NONE        = 0,
  REDF_MANIPULATOR_TYPE_SCALE       = 1,
  REDF_MANIPULATOR_TYPE_ROTATION    = 2,
  REDF_MANIPULATOR_TYPE_TRANSLATION = 3,
} RedFManipulatorType;

typedef enum RedFImageType {
  REDF_IMAGE_TYPE_GRAYSCALE        = 0,
  REDF_IMAGE_TYPE_COLOR_RGB        = 1,
  REDF_IMAGE_TYPE_COLOR_ALPHA_RGBA = 2,
  REDF_IMAGE_TYPE_UNDEFINED        = 3,
} RedFImageType;

typedef enum RedFLightType {
  REDF_LIGHT_TYPE_POINT       = 0,
  REDF_LIGHT_TYPE_DIRECTIONAL = 1,
  REDF_LIGHT_TYPE_SPOT        = 2,
  REDF_LIGHT_TYPE_AREA        = 3,
} RedFLightType;

typedef enum RedFWindowMode {
  REDF_WINDOW_MODE_WINDOW     = 0,
  REDF_WINDOW_MODE_FULLSCREEN = 1,
  REDF_WINDOW_MODE_GAME_MODE  = 2,
} RedFWindowMode;

#ifndef REDGPU_F_DECLSPEC
#define REDGPU_F_DECLSPEC
#endif

REDGPU_F_DECLSPEC int                 redFMain                                (const RedFEvents * events, int windowWidth, int windowHeight, RedFWindowMode windowMode, RedFBool32 useOpenGL32, RedFBool32 windowIsDecorated, RedFBool32 windowIsResizable, int msaaSamples, uint64_t optionalSettingsCount, const void * optionalSettings);
REDGPU_F_DECLSPEC void                redFSetEscapeQuitsApp                   (RedFBool32 quitOnEsc);
REDGPU_F_DECLSPEC void                redFSetWindowShape                      (int width, int height);
REDGPU_F_DECLSPEC void                redFSetWindowPosition                   (int x, int y);
REDGPU_F_DECLSPEC void                redFSetWindowTitle                      (const char * title);
REDGPU_F_DECLSPEC void                redFSetWindowTitleW                     (const wchar_t * title);

REDGPU_F_DECLSPEC RedFHandleNode *    redFCreateNode                          (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyNode                         (RedFHandleNode * handles);
REDGPU_F_DECLSPEC void                redFNodeCopyToNode                      (RedFHandleNode handle, RedFHandleNode to);
REDGPU_F_DECLSPEC void                redFNodeCopyToManipulator               (RedFHandleNode handle, RedFHandleManipulator to);
REDGPU_F_DECLSPEC void                redFNodeDraw                            (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetGlobalPositionX              (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetGlobalPositionY              (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetGlobalPositionZ              (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetGlobalOrientationQuaternionX (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetGlobalOrientationQuaternionY (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetGlobalOrientationQuaternionZ (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetGlobalOrientationQuaternionW (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetScaleX                       (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetScaleY                       (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetScaleZ                       (RedFHandleNode handle);
REDGPU_F_DECLSPEC void                redFNodeGetGlobalTransformMatrix        (RedFHandleNode handle, void * outMat4);
REDGPU_F_DECLSPEC float               redFNodeGetSideDirX                     (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetSideDirY                     (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetSideDirZ                     (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetUpDirX                       (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetUpDirY                       (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetUpDirZ                       (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetLookAtDirX                   (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetLookAtDirY                   (RedFHandleNode handle);
REDGPU_F_DECLSPEC float               redFNodeGetLookAtDirZ                   (RedFHandleNode handle);
REDGPU_F_DECLSPEC void                redFNodeSetGlobalPosition               (RedFHandleNode handle, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFNodeSetGlobalOrientationQuaternion  (RedFHandleNode handle, float x, float y, float z, float w);
REDGPU_F_DECLSPEC void                redFNodeSetScale                        (RedFHandleNode handle, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFNodeLookAt                          (RedFHandleNode handle, float x, float y, float z, float upX, float upY, float upZ);
REDGPU_F_DECLSPEC void                redFNodeRotateDeg                       (RedFHandleNode handle, float degrees, float axisX, float axisY, float axisZ);

REDGPU_F_DECLSPEC RedFHandleCamera *  redFCreateCamera                        (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyCamera                       (RedFHandleCamera * handles);
REDGPU_F_DECLSPEC RedFHandleNode      redFCameraCastToNode                    (RedFHandleCamera handle);
REDGPU_F_DECLSPEC void                redFCameraSetFov                        (RedFHandleCamera handle, float fov);
REDGPU_F_DECLSPEC void                redFCameraSetNearClip                   (RedFHandleCamera handle, float nearDist);
REDGPU_F_DECLSPEC void                redFCameraSetFarClip                    (RedFHandleCamera handle, float farDist);
REDGPU_F_DECLSPEC void                redFCameraSetLensOffset                 (RedFHandleCamera handle, float lensOffsetX, float lensOffsetY);
REDGPU_F_DECLSPEC void                redFCameraSetAspectRatio                (RedFHandleCamera handle, float aspectRatio);
REDGPU_F_DECLSPEC void                redFCameraSetForceAspectRatio           (RedFHandleCamera handle, RedFBool32 forceAspectRatio);
REDGPU_F_DECLSPEC float               redFCameraGetFov                        (RedFHandleCamera handle);
REDGPU_F_DECLSPEC float               redFCameraGetNearClip                   (RedFHandleCamera handle);
REDGPU_F_DECLSPEC float               redFCameraGetFarClip                    (RedFHandleCamera handle);
REDGPU_F_DECLSPEC void                redFCameraGetLensOffset                 (RedFHandleCamera handle, void * outVec2);
REDGPU_F_DECLSPEC RedFBool32          redFCameraGetForceAspectRatio           (RedFHandleCamera handle);
REDGPU_F_DECLSPEC float               redFCameraGetAspectRatio                (RedFHandleCamera handle);
REDGPU_F_DECLSPEC void                redFCameraSetupPerspective              (RedFHandleCamera handle, RedFBool32 vFlip, float fov, float nearDist, float farDist, float lensOffsetX, float lensOffsetY);
REDGPU_F_DECLSPEC void                redFCameraSetupOffAxisViewPortal        (RedFHandleCamera handle, float topLeftX, float topLeftY, float topLeftZ, float bottomLeftX, float bottomLeftY, float bottomLeftZ, float bottomRightX, float bottomRightY, float bottomRightZ);
REDGPU_F_DECLSPEC void                redFCameraSetVFlip                      (RedFHandleCamera handle, RedFBool32 vFlip);
REDGPU_F_DECLSPEC RedFBool32          redFCameraIsVFlipped                    (RedFHandleCamera handle);
REDGPU_F_DECLSPEC void                redFCameraEnableOrtho                   (RedFHandleCamera handle);
REDGPU_F_DECLSPEC void                redFCameraDisableOrtho                  (RedFHandleCamera handle);
REDGPU_F_DECLSPEC RedFBool32          redFCameraGetOrtho                      (RedFHandleCamera handle);
REDGPU_F_DECLSPEC float               redFCameraGetImagePlaneDistance         (RedFHandleCamera handle);
REDGPU_F_DECLSPEC void                redFCameraBegin                         (RedFHandleCamera handle);
REDGPU_F_DECLSPEC void                redFCameraEnd                           (RedFHandleCamera handle);
REDGPU_F_DECLSPEC void                redFCameraGetProjectionMatrix           (RedFHandleCamera handle, void * outMat4);
REDGPU_F_DECLSPEC void                redFCameraGetModelViewMatrix            (RedFHandleCamera handle, void * outMat4);
REDGPU_F_DECLSPEC void                redFCameraGetModelViewProjectionMatrix  (RedFHandleCamera handle, void * outMat4);
REDGPU_F_DECLSPEC void                redFCameraWorldToScreen                 (RedFHandleCamera handle, float worldX, float worldY, float worldZ, void * outVec3);
REDGPU_F_DECLSPEC void                redFCameraScreenToWorld                 (RedFHandleCamera handle, float screenX, float screenY, float screenZ, void * outVec3);
REDGPU_F_DECLSPEC void                redFCameraWorldToCamera                 (RedFHandleCamera handle, float worldX, float worldY, float worldZ, void * outVec3);
REDGPU_F_DECLSPEC void                redFCameraCameraToWorld                 (RedFHandleCamera handle, float cameraX, float cameraY, float cameraZ, void * outVec3);
REDGPU_F_DECLSPEC void                redFCameraDrawFrustum                   (RedFHandleCamera handle);

REDGPU_F_DECLSPEC RedFHandleFirstPersonCamera * redFCreateFirstPersonCamera   (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyFirstPersonCamera            (RedFHandleFirstPersonCamera * handles);
REDGPU_F_DECLSPEC RedFHandleCamera    redFFirstPersonCameraCastToCamera       (RedFHandleFirstPersonCamera handle);
REDGPU_F_DECLSPEC RedFHandleNode      redFFirstPersonCameraCastToNode         (RedFHandleFirstPersonCamera handle);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraBegin              (RedFHandleFirstPersonCamera handle);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraEnd                (RedFHandleFirstPersonCamera handle);
REDGPU_F_DECLSPEC RedFBool32          redFFirstPersonCameraControlIsEnabled   (RedFHandleFirstPersonCamera handle);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraControlToggle      (RedFHandleFirstPersonCamera handle);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraControlEnable      (RedFHandleFirstPersonCamera handle);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraControlDisable     (RedFHandleFirstPersonCamera handle);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyUp           (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyDown         (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyLeft         (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyRight        (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyForward      (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyBackward     (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyRollLeft     (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyRollRight    (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetKeyRollReset    (RedFHandleFirstPersonCamera handle, int key);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetMoveSpeed       (RedFHandleFirstPersonCamera handle, float moveSpeed);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetRollSpeed       (RedFHandleFirstPersonCamera handle, float rollSpeed);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetSensitivity     (RedFHandleFirstPersonCamera handle, float sensitivity);
REDGPU_F_DECLSPEC void                redFFirstPersonCameraSetUpVector        (RedFHandleFirstPersonCamera handle, float x, float y, float z);

REDGPU_F_DECLSPEC RedFHandleMesh *    redFCreateMesh                          (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyMesh                         (RedFHandleMesh * handles);
REDGPU_F_DECLSPEC void                redFMeshSetMode                         (RedFHandleMesh handle, RedFPrimitiveMode mode);
REDGPU_F_DECLSPEC RedFPrimitiveMode   redFMeshGetMode                         (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshClear                           (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshAddVertex                       (RedFHandleMesh handle, float vx, float vy, float vz);
REDGPU_F_DECLSPEC void                redFMeshAddVertices                     (RedFHandleMesh handle, void * vertVec3s, uint64_t vertVec3sCount);
REDGPU_F_DECLSPEC void                redFMeshRemoveVertex                    (RedFHandleMesh handle, unsigned index);
REDGPU_F_DECLSPEC void                redFMeshClearVertices                   (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshSetVertex                       (RedFHandleMesh handle, unsigned index, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFMeshGetVertex                       (RedFHandleMesh handle, unsigned index, void * outVec3);
REDGPU_F_DECLSPEC uint64_t            redFMeshGetNumVertices                  (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void *              redFMeshGetVerticesPointer              (RedFHandleMesh handle); // vec3 *
REDGPU_F_DECLSPEC RedFBool32          redFMeshHasVertices                     (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshHaveVertsChanged                (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshMergeDuplicateVertices          (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshGetCentroid                     (RedFHandleMesh handle, void * outVec3);
REDGPU_F_DECLSPEC void                redFMeshEnableNormals                   (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshDisableNormals                  (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshUsingNormals                    (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshAddNormal                       (RedFHandleMesh handle, float nx, float ny, float nz);
REDGPU_F_DECLSPEC void                redFMeshAddNormals                      (RedFHandleMesh handle, void * normVec3s, uint64_t normVec3sCount);
REDGPU_F_DECLSPEC void                redFMeshRemoveNormal                    (RedFHandleMesh handle, unsigned index);
REDGPU_F_DECLSPEC void                redFMeshClearNormals                    (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshSetNormal                       (RedFHandleMesh handle, unsigned index, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFMeshGetNormal                       (RedFHandleMesh handle, unsigned index, void * outVec3);
REDGPU_F_DECLSPEC uint64_t            redFMeshGetNumNormals                   (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void *              redFMeshGetNormalsPointer               (RedFHandleMesh handle); // vec3 *
REDGPU_F_DECLSPEC RedFBool32          redFMeshHasNormals                      (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshHaveNormalsChanged              (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshSmoothNormals                   (RedFHandleMesh handle, float angle);
REDGPU_F_DECLSPEC void                redFMeshFlatNormals                     (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshEnableColors                    (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshDisableColors                   (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshUsingColors                     (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshAddColor                        (RedFHandleMesh handle, float cr, float cg, float cb, float ca);
REDGPU_F_DECLSPEC void                redFMeshAddColors                       (RedFHandleMesh handle, void * colVec4s, uint64_t colVec4sCount);
REDGPU_F_DECLSPEC void                redFMeshRemoveColor                     (RedFHandleMesh handle, unsigned index);
REDGPU_F_DECLSPEC void                redFMeshClearColors                     (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshSetColor                        (RedFHandleMesh handle, unsigned index, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFMeshGetColor                        (RedFHandleMesh handle, unsigned index, void * outVec4);
REDGPU_F_DECLSPEC uint64_t            redFMeshGetNumColors                    (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void *              redFMeshGetColorsPointer                (RedFHandleMesh handle); // vec4 *
REDGPU_F_DECLSPEC RedFBool32          redFMeshHasColors                       (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshHaveColorsChanged               (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshEnableTextures                  (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshDisableTextures                 (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshUsingTextures                   (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshAddTexCoord                     (RedFHandleMesh handle, float tu, float tv);
REDGPU_F_DECLSPEC void                redFMeshAddTexCoords                    (RedFHandleMesh handle, void * texVec2s, uint64_t texVec2sCount);
REDGPU_F_DECLSPEC void                redFMeshRemoveTexCoord                  (RedFHandleMesh handle, unsigned index);
REDGPU_F_DECLSPEC void                redFMeshClearTexCoords                  (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshSetTexCoord                     (RedFHandleMesh handle, unsigned index, float u, float v);
REDGPU_F_DECLSPEC void                redFMeshGetTexCoord                     (RedFHandleMesh handle, unsigned index, void * outVec2);
REDGPU_F_DECLSPEC uint64_t            redFMeshGetNumTexCoords                 (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void *              redFMeshGetTexCoordsPointer             (RedFHandleMesh handle); // vec2 *
REDGPU_F_DECLSPEC RedFBool32          redFMeshHasTexCoords                    (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshHaveTexCoordsChanged            (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshEnableIndices                   (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshDisableIndices                  (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshUsingIndices                    (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshAddIndex                        (RedFHandleMesh handle, unsigned index);
REDGPU_F_DECLSPEC void                redFMeshAddIndices                      (RedFHandleMesh handle, unsigned * indexes, uint64_t indexesCount);
REDGPU_F_DECLSPEC void                redFMeshRemoveIndex                     (RedFHandleMesh handle, unsigned index);
REDGPU_F_DECLSPEC void                redFMeshClearIndices                    (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshSetIndex                        (RedFHandleMesh handle, unsigned index, unsigned value);
REDGPU_F_DECLSPEC unsigned            redFMeshGetIndex                        (RedFHandleMesh handle, unsigned index);
REDGPU_F_DECLSPEC uint64_t            redFMeshGetNumIndices                   (RedFHandleMesh handle);
REDGPU_F_DECLSPEC unsigned *          redFMeshGetIndexPointer                 (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshHasIndices                      (RedFHandleMesh handle);
REDGPU_F_DECLSPEC RedFBool32          redFMeshHaveIndicesChanged              (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshSetupIndicesAuto                (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshAddTriangle                     (RedFHandleMesh handle, unsigned index1, unsigned index2, unsigned index3);
REDGPU_F_DECLSPEC void                redFMeshSetColorForIndices              (RedFHandleMesh handle, unsigned startIndex, unsigned endIndex, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFMeshDrawVertices                    (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshDrawWireframe                   (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshDraw                            (RedFHandleMesh handle);
REDGPU_F_DECLSPEC void                redFMeshDrawWithRenderMode              (RedFHandleMesh handle, RedFPolyRenderMode renderMode);

REDGPU_F_DECLSPEC RedFHandleImage *   redFCreateImage                         (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyImage                        (RedFHandleImage * handles);
REDGPU_F_DECLSPEC void                redFImageAllocate                       (RedFHandleImage handle, int w, int h, RedFImageType type);
REDGPU_F_DECLSPEC RedFBool32          redFImageIsAllocated                    (RedFHandleImage handle);
REDGPU_F_DECLSPEC int                 redFImageGetWidth                       (RedFHandleImage handle);
REDGPU_F_DECLSPEC int                 redFImageGetHeight                      (RedFHandleImage handle);
REDGPU_F_DECLSPEC RedFImageType       redFImageGetImageType                   (RedFHandleImage handle);
REDGPU_F_DECLSPEC void                redFImageClear                          (RedFHandleImage handle);
REDGPU_F_DECLSPEC RedFBool32          redFImageLoad                           (RedFHandleImage handle, const char * fileName);
REDGPU_F_DECLSPEC RedFBool32          redFImageLoadFromMemory                 (RedFHandleImage handle, uint64_t imageMemoryBytesCount, const void * imageMemory);
REDGPU_F_DECLSPEC void                redFImageSave                           (RedFHandleImage handle, const char * fileName);
REDGPU_F_DECLSPEC void                redFImageGrabScreen                     (RedFHandleImage handle, int x, int y, int w, int h);
REDGPU_F_DECLSPEC void                redFImageSetColor                       (RedFHandleImage handle, int x, int y, int r, int g, int b, int a);
REDGPU_F_DECLSPEC void                redFImageGetColor                       (RedFHandleImage handle, int x, int y, unsigned char * outR, unsigned char * outG, unsigned char * outB, unsigned char * outA);
REDGPU_F_DECLSPEC void                redFImageResize                         (RedFHandleImage handle, int newWidth, int newHeight);
REDGPU_F_DECLSPEC void                redFImageCrop                           (RedFHandleImage handle, int x, int y, int w, int h);
REDGPU_F_DECLSPEC void                redFImageRotate90                       (RedFHandleImage handle, int rotation);
REDGPU_F_DECLSPEC void                redFImageMirror                         (RedFHandleImage handle, RedFBool32 vertical, RedFBool32 horizontal);
REDGPU_F_DECLSPEC void                redFImageSetTextureWrap                 (RedFHandleImage handle, int wrapModeHorizontal, int wrapModeVertical);
REDGPU_F_DECLSPEC void                redFImageSetTextureMinMagFilter         (RedFHandleImage handle, int minFilter, int magFilter);
REDGPU_F_DECLSPEC void                redFImageSetTextureCompareModeFunc      (RedFHandleImage handle, int compareMode, int compareFunc);
REDGPU_F_DECLSPEC void                redFImageSetAnchorPercent               (RedFHandleImage handle, float x, float y);
REDGPU_F_DECLSPEC void                redFImageSetAnchorPoint                 (RedFHandleImage handle, float x, float y);
REDGPU_F_DECLSPEC void                redFImageResetAnchor                    (RedFHandleImage handle);
REDGPU_F_DECLSPEC void                redFImageUpdate                         (RedFHandleImage handle);
REDGPU_F_DECLSPEC void                redFImageBind                           (RedFHandleImage handle);
REDGPU_F_DECLSPEC void                redFImageUnbind                         (RedFHandleImage handle);
REDGPU_F_DECLSPEC void                redFImageDraw                           (RedFHandleImage handle, float x, float y, float z, float w, float h);
REDGPU_F_DECLSPEC void                redFImageDrawSubsection                 (RedFHandleImage handle, float x, float y, float z, float w, float h, float sx, float sy, float sw, float sh);

REDGPU_F_DECLSPEC RedFHandleFbo *     redFCreateFbo                           (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyFbo                          (RedFHandleFbo * handles);
REDGPU_F_DECLSPEC void                redFFboAllocate                         (RedFHandleFbo handle, int width, int height, const RedFFboSettings * optionalSettings);
REDGPU_F_DECLSPEC RedFBool32          redFFboIsAllocated                      (RedFHandleFbo handle);
REDGPU_F_DECLSPEC void                redFFboBegin                            (RedFHandleFbo handle, RedFBool32 setupScreenDefaultIs1);
REDGPU_F_DECLSPEC void                redFFboActivateAllDrawBuffers           (RedFHandleFbo handle);
REDGPU_F_DECLSPEC void                redFFboEnd                              (RedFHandleFbo handle);
REDGPU_F_DECLSPEC void                redFFboSetTextureWrap                   (RedFHandleFbo handle, int fboAttachmentPoint, int wrapModeHorizontal, int wrapModeVertical);
REDGPU_F_DECLSPEC void                redFFboSetTextureMinMagFilter           (RedFHandleFbo handle, int fboAttachmentPoint, int minFilter, int magFilter);
REDGPU_F_DECLSPEC void                redFFboSetTextureCompareModeFunc        (RedFHandleFbo handle, int fboAttachmentPoint, int compareMode, int compareFunc);
REDGPU_F_DECLSPEC void                redFFboSetDepthTextureWrap              (RedFHandleFbo handle, int wrapModeHorizontal, int wrapModeVertical);
REDGPU_F_DECLSPEC void                redFFboSetDepthTextureMinMagFilter      (RedFHandleFbo handle, int minFilter, int magFilter);
REDGPU_F_DECLSPEC void                redFFboSetDepthTextureCompareModeFunc   (RedFHandleFbo handle, int compareMode, int compareFunc);
REDGPU_F_DECLSPEC void                redFFboSetDepthTextureRGToRGBASwizzles  (RedFHandleFbo handle, RedFBool32 rToRGBSwizzles);
REDGPU_F_DECLSPEC void                redFFboBind                             (RedFHandleFbo handle, int fboAttachmentPoint);
REDGPU_F_DECLSPEC void                redFFboUnbind                           (RedFHandleFbo handle, int fboAttachmentPoint);
REDGPU_F_DECLSPEC void                redFFboDraw                             (RedFHandleFbo handle, int fboAttachmentPoint, float x, float y, float width, float height);
REDGPU_F_DECLSPEC void                redFFboDepthDraw                        (RedFHandleFbo handle, float x, float y, float width, float height);
REDGPU_F_DECLSPEC void                redFFboReadToImage                      (RedFHandleFbo handle, int fboAttachmentPoint, RedFHandleImage image);
REDGPU_F_DECLSPEC void                redFFboSave                             (RedFHandleFbo handle, int fboAttachmentPoint, const char * fileName);
REDGPU_F_DECLSPEC void                redFFboClear                            (RedFHandleFbo handle);
REDGPU_F_DECLSPEC void                redFFboClearColorBuffer                 (RedFHandleFbo handle, int bufferIndex, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFFboClearDepthBuffer                 (RedFHandleFbo handle, float depth);
REDGPU_F_DECLSPEC void                redFFboClearStencilBuffer               (RedFHandleFbo handle, int stencil);
REDGPU_F_DECLSPEC void                redFFboClearDepthStencilBuffer          (RedFHandleFbo handle, float depth, int stencil);

REDGPU_F_DECLSPEC RedFHandleLight *   redFCreateLight                         (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyLight                        (RedFHandleLight * handles);
REDGPU_F_DECLSPEC RedFHandleNode      redFLightCastToNode                     (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetup                          (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightEnable                         (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightDisable                        (RedFHandleLight handle);
REDGPU_F_DECLSPEC RedFBool32          redFLightGetIsEnabled                   (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetDirectional                 (RedFHandleLight handle);
REDGPU_F_DECLSPEC RedFBool32          redFLightGetIsDirectional               (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetSpotlight                   (RedFHandleLight handle, float spotCutOffDefaultIs45, float exponentDefaultIs0);
REDGPU_F_DECLSPEC RedFBool32          redFLightGetIsSpotlight                 (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetSpotlightCutOff             (RedFHandleLight handle, float spotCutOff);
REDGPU_F_DECLSPEC float               redFLightGetSpotlightCutOff             (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetSpotConcentration           (RedFHandleLight handle, float exponent);
REDGPU_F_DECLSPEC float               redFLightGetSpotConcentration           (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetPointLight                  (RedFHandleLight handle);
REDGPU_F_DECLSPEC RedFBool32          redFLightGetIsPointLight                (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetAttenuation                 (RedFHandleLight handle, float constantDefaultIs1, float linearDefaultIs0, float quadraticDefaultIs0);
REDGPU_F_DECLSPEC float               redFLightGetAttenuationConstant         (RedFHandleLight handle);
REDGPU_F_DECLSPEC float               redFLightGetAttenuationLinear           (RedFHandleLight handle);
REDGPU_F_DECLSPEC float               redFLightGetAttenuationQuadratic        (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetAreaLight                   (RedFHandleLight handle, float width, float height);
REDGPU_F_DECLSPEC RedFBool32          redFLightGetIsAreaLight                 (RedFHandleLight handle);
REDGPU_F_DECLSPEC RedFLightType       redFLightGetType                        (RedFHandleLight handle);
REDGPU_F_DECLSPEC void                redFLightSetAmbientColor                (RedFHandleLight handle, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFLightSetDiffuseColor                (RedFHandleLight handle, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFLightSetSpecularColor               (RedFHandleLight handle, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFLightGetAmbientColor                (RedFHandleLight handle, void * outVec4);
REDGPU_F_DECLSPEC void                redFLightGetDiffuseColor                (RedFHandleLight handle, void * outVec4);
REDGPU_F_DECLSPEC void                redFLightGetSpecularColor               (RedFHandleLight handle, void * outVec4);
REDGPU_F_DECLSPEC int                 redFLightGetLightID                     (RedFHandleLight handle);

REDGPU_F_DECLSPEC RedFHandleMaterial * redFCreateMaterial                     (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyMaterial                     (RedFHandleMaterial * handles);
REDGPU_F_DECLSPEC void                redFMaterialSetup                       (RedFHandleMaterial handle, const RedFMaterialSettings * settings);
REDGPU_F_DECLSPEC void                redFMaterialSetDiffuseColor             (RedFHandleMaterial handle, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFMaterialSetAmbientColor             (RedFHandleMaterial handle, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFMaterialSetSpecularColor            (RedFHandleMaterial handle, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFMaterialSetEmissiveColor            (RedFHandleMaterial handle, float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFMaterialSetShininess                (RedFHandleMaterial handle, float nShininess);
REDGPU_F_DECLSPEC void                redFMaterialGetDiffuseColor             (RedFHandleMaterial handle, void * outVec4);
REDGPU_F_DECLSPEC void                redFMaterialGetAmbientColor             (RedFHandleMaterial handle, void * outVec4);
REDGPU_F_DECLSPEC void                redFMaterialGetSpecularColor            (RedFHandleMaterial handle, void * outVec4);
REDGPU_F_DECLSPEC void                redFMaterialGetEmissiveColor            (RedFHandleMaterial handle, void * outVec4);
REDGPU_F_DECLSPEC float               redFMaterialGetShininess                (RedFHandleMaterial handle);
REDGPU_F_DECLSPEC void                redFMaterialGetSettings                 (RedFHandleMaterial handle, RedFMaterialSettings * outSettings, char ** outPostFragment, char ** outCustomUniforms); // redFFree() outPostFragment[0] and outCustomUniforms[0] yourself
REDGPU_F_DECLSPEC void                redFMaterialSetCustomUniform4f          (RedFHandleMaterial handle, const char * uniformName, float v0, float v1, float v2, float v3);
REDGPU_F_DECLSPEC void                redFMaterialSetCustomUniformMatrix4f    (RedFHandleMaterial handle, const char * uniformName, void * mat4);
REDGPU_F_DECLSPEC void                redFMaterialSetCustomUniformImage       (RedFHandleMaterial handle, const char * uniformName, RedFHandleImage image, int textureLocation);
REDGPU_F_DECLSPEC void                redFMaterialSetCustomUniformFbo         (RedFHandleMaterial handle, const char * uniformName, RedFHandleFbo fbo, int fboAttachmentPoint, int textureLocation);
REDGPU_F_DECLSPEC void                redFMaterialSetCustomUniformFboDepth    (RedFHandleMaterial handle, const char * uniformName, RedFHandleFbo fbo, int textureLocation);
REDGPU_F_DECLSPEC void                redFMaterialBegin                       (RedFHandleMaterial handle);
REDGPU_F_DECLSPEC void                redFMaterialEnd                         (RedFHandleMaterial handle);

REDGPU_F_DECLSPEC RedFHandleShader *  redFCreateShader                        (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyShader                       (RedFHandleShader * handles);
REDGPU_F_DECLSPEC RedFBool32          redFShaderLoad                          (RedFHandleShader handle, const char * vertexFileName, const char * fragmentFileName);
REDGPU_F_DECLSPEC void                redFShaderBegin                         (RedFHandleShader handle);
REDGPU_F_DECLSPEC void                redFShaderSetUniform4f                  (RedFHandleShader handle, const char * uniformName, float v0, float v1, float v2, float v3);
REDGPU_F_DECLSPEC void                redFShaderSetUniform4fv                 (RedFHandleShader handle, const char * uniformName, void * v, int count);
REDGPU_F_DECLSPEC void                redFShaderSetUniformMatrix4f            (RedFHandleShader handle, const char * uniformName, void * mat4);
REDGPU_F_DECLSPEC void                redFShaderSetUniformImage               (RedFHandleShader handle, const char * uniformName, RedFHandleImage image, int textureLocation);
REDGPU_F_DECLSPEC void                redFShaderSetUniformFbo                 (RedFHandleShader handle, const char * uniformName, RedFHandleFbo fbo, int fboAttachmentPoint, int textureLocation);
REDGPU_F_DECLSPEC void                redFShaderSetUniformFboDepth            (RedFHandleShader handle, const char * uniformName, RedFHandleFbo fbo, int textureLocation);
REDGPU_F_DECLSPEC void                redFShaderEnd                           (RedFHandleShader handle);

REDGPU_F_DECLSPEC RedFHandleManipulator * redFCreateManipulator               (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyManipulator                  (RedFHandleManipulator * handles);
REDGPU_F_DECLSPEC void                redFManipulatorCopyToNode               (RedFHandleManipulator handle, RedFHandleNode to);
REDGPU_F_DECLSPEC void                redFManipulatorCopyToManipulator        (RedFHandleManipulator handle, RedFHandleManipulator to);
REDGPU_F_DECLSPEC void                redFManipulatorDraw                     (RedFHandleManipulator handle, RedFHandleCamera camera);
REDGPU_F_DECLSPEC void                redFManipulatorGetMatrix                (RedFHandleManipulator handle, void * outMat4);
REDGPU_F_DECLSPEC void                redFManipulatorGetScale                 (RedFHandleManipulator handle, void * outVec3);
REDGPU_F_DECLSPEC void                redFManipulatorGetRotationQuaternion    (RedFHandleManipulator handle, void * outVec4);
REDGPU_F_DECLSPEC void                redFManipulatorGetRotationAxisAngleDeg  (RedFHandleManipulator handle, void * outVec4);
REDGPU_F_DECLSPEC void                redFManipulatorGetTranslation           (RedFHandleManipulator handle, void * outVec3);
REDGPU_F_DECLSPEC void                redFManipulatorSetScale                 (RedFHandleManipulator handle, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFManipulatorSetRotation              (RedFHandleManipulator handle, float x, float y, float z, float w);
REDGPU_F_DECLSPEC void                redFManipulatorSetTranslation           (RedFHandleManipulator handle, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFManipulatorScale                    (RedFHandleManipulator handle, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFManipulatorRotate                   (RedFHandleManipulator handle, float x, float y, float z, float w);
REDGPU_F_DECLSPEC void                redFManipulatorTranslate                (RedFHandleManipulator handle, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFManipulatorToggleScale              (RedFHandleManipulator handle);
REDGPU_F_DECLSPEC void                redFManipulatorToggleRotation           (RedFHandleManipulator handle);
REDGPU_F_DECLSPEC void                redFManipulatorToggleTranslation        (RedFHandleManipulator handle);
REDGPU_F_DECLSPEC float               redFManipulatorGetManipulatorScale      (RedFHandleManipulator handle);
REDGPU_F_DECLSPEC void                redFManipulatorSetManipulatorScale      (RedFHandleManipulator handle, float scale);
REDGPU_F_DECLSPEC RedFManipulatorType redFManipulatorGetManipulatorType       (RedFHandleManipulator handle);
REDGPU_F_DECLSPEC void                redFManipulatorSetManipulatorType       (RedFHandleManipulator handle, RedFManipulatorType type);
REDGPU_F_DECLSPEC void                redFManipulatorSetManipulatorColors     (RedFHandleManipulator handle, int xr, int xg, int xb, int xa, int yr, int yg, int yb, int ya, int zr, int zg, int zb, int za, int wr, int wg, int wb, int wa, int sr, int sg, int sb, int sa);
REDGPU_F_DECLSPEC RedFBool32          redFManipulatorIsEnabled                (RedFHandleManipulator handle);
REDGPU_F_DECLSPEC void                redFManipulatorEnable                   (RedFHandleManipulator handle);
REDGPU_F_DECLSPEC void                redFManipulatorDisable                  (RedFHandleManipulator handle);

REDGPU_F_DECLSPEC RedFHandleAssimp *  redFCreateAssimp                        (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyAssimp                       (RedFHandleAssimp * handles);
REDGPU_F_DECLSPEC void                redFAssimpLoadModel                     (RedFHandleAssimp handle, const char * fileName, RedFBool32 optimize);
REDGPU_F_DECLSPEC unsigned            redFAssimpGetNumMeshes                  (RedFHandleAssimp handle);
REDGPU_F_DECLSPEC void                redFAssimpGetMeshName                   (RedFHandleAssimp handle, unsigned index, uint64_t * outCharsCountIncludingNullTerminator, char * outChars);
REDGPU_F_DECLSPEC void                redFAssimpGetMesh                       (RedFHandleAssimp handle, unsigned index, RedFHandleMesh replaceMesh);

REDGPU_F_DECLSPEC RedFHandleEquiMap * redFCreateEquiMap                       (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyEquiMap                      (RedFHandleEquiMap * handles);
REDGPU_F_DECLSPEC void                redFEquiMapSetup                        (RedFHandleEquiMap handle, int size);
REDGPU_F_DECLSPEC void                redFEquiMapRender                       (RedFHandleEquiMap handle, void (*drawEquiScene)(void *), void * userData, float cubePosX, float cubePosY, float cubePosZ);
REDGPU_F_DECLSPEC void                redFEquiMapDraw                         (RedFHandleEquiMap handle, float x, float y, float w, float h);

REDGPU_F_DECLSPEC RedFHandleImgui *   redFCreateImgui                         (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyImgui                        (RedFHandleImgui * handles);
REDGPU_F_DECLSPEC void                redFImguiSetup                          (RedFHandleImgui handle);
REDGPU_F_DECLSPEC void                redFImguiBegin                          (RedFHandleImgui handle);
REDGPU_F_DECLSPEC void                redFImguiEnd                            (RedFHandleImgui handle);

REDGPU_F_DECLSPEC RedFHandleSoundPlayer * redFCreateSoundPlayer               (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroySoundPlayer                  (RedFHandleSoundPlayer * handles);
REDGPU_F_DECLSPEC RedFBool32          redFSoundPlayerLoad                     (RedFHandleSoundPlayer handle, const char * fileName, RedFBool32 streamDefaultIs0);
REDGPU_F_DECLSPEC void                redFSoundPlayerUnload                   (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC void                redFSoundPlayerPlay                     (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC void                redFSoundPlayerStop                     (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC void                redFSoundPlayerSetVolume                (RedFHandleSoundPlayer handle, float volume0to1);
REDGPU_F_DECLSPEC void                redFSoundPlayerSetPan                   (RedFHandleSoundPlayer handle, float panMinus1to1);
REDGPU_F_DECLSPEC void                redFSoundPlayerSetSpeed                 (RedFHandleSoundPlayer handle, float speedDefaultIs1);
REDGPU_F_DECLSPEC void                redFSoundPlayerSetPaused                (RedFHandleSoundPlayer handle, RedFBool32 paused);
REDGPU_F_DECLSPEC void                redFSoundPlayerSetLoop                  (RedFHandleSoundPlayer handle, RedFBool32 loop);
REDGPU_F_DECLSPEC void                redFSoundPlayerSetMultiPlay             (RedFHandleSoundPlayer handle, RedFBool32 multiplay);
REDGPU_F_DECLSPEC void                redFSoundPlayerSetPosition              (RedFHandleSoundPlayer handle, float percent0to1);
REDGPU_F_DECLSPEC void                redFSoundPlayerSetPositionMS            (RedFHandleSoundPlayer handle, int milliseconds);
REDGPU_F_DECLSPEC int                 redFSoundPlayerGetPositionMS            (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC float               redFSoundPlayerGetPosition              (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC RedFBool32          redFSoundPlayerIsPlaying                (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC float               redFSoundPlayerGetSpeed                 (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC float               redFSoundPlayerGetPan                   (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC float               redFSoundPlayerGetVolume                (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC RedFBool32          redFSoundPlayerIsLoaded                 (RedFHandleSoundPlayer handle);
REDGPU_F_DECLSPEC void                redFSoundSetVolume                      (float volume0to1);
REDGPU_F_DECLSPEC void                redFSoundShutdown                       (void);
REDGPU_F_DECLSPEC void                redFSoundStopAll                        (void);
REDGPU_F_DECLSPEC void                redFSoundUpdate                         (void);

REDGPU_F_DECLSPEC RedFHandleDirectory * redFCreateDirectory                   (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyDirectory                    (RedFHandleDirectory * handles);
REDGPU_F_DECLSPEC void                redFDirectoryOpen                       (RedFHandleDirectory handle, const char * path);
REDGPU_F_DECLSPEC void                redFDirectoryOpenFromCurrentWorkingDirectory(RedFHandleDirectory handle, const char * path);
REDGPU_F_DECLSPEC void                redFDirectoryClose                      (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC uint64_t            redFDirectoryListDir                    (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryCreate                     (RedFHandleDirectory handle, RedFBool32 recursiveDefaultIs0);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryExists                     (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC void                redFDirectoryPath                       (RedFHandleDirectory handle, char ** outPath, uint64_t * outPathBytesCount); // redFFree() outPath[0] yourself
REDGPU_F_DECLSPEC void                redFDirectoryGetAbsolutePath            (RedFHandleDirectory handle, char ** outAbsolutePath, uint64_t * outAbsolutePathBytesCount); // redFFree() outAbsolutePath[0] yourself
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryCanRead                    (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryCanWrite                   (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryCanExecute                 (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryIsDirectory                (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryIsHidden                   (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC void                redFDirectorySetWriteable               (RedFHandleDirectory handle, RedFBool32 writeableDefaultIs1);
REDGPU_F_DECLSPEC void                redFDirectorySetReadable                (RedFHandleDirectory handle, RedFBool32 readableDefaultIs1);
REDGPU_F_DECLSPEC void                redFDirectorySetExecutable              (RedFHandleDirectory handle, RedFBool32 executableDefaultIs1);
REDGPU_F_DECLSPEC void                redFDirectorySetShowHidden              (RedFHandleDirectory handle, RedFBool32 showHidden);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryCopyTo                     (RedFHandleDirectory handle, const char * path, RedFBool32 bRelativeToDataDefaultIs1, RedFBool32 overwriteDefaultIs0);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryMoveTo                     (RedFHandleDirectory handle, const char * path, RedFBool32 bRelativeToDataDefaultIs1, RedFBool32 overwriteDefaultIs0);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryRenameTo                   (RedFHandleDirectory handle, const char * path, RedFBool32 bRelativeToDataDefaultIs1, RedFBool32 overwriteDefaultIs0);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryRemove                     (RedFHandleDirectory handle, RedFBool32 recursive);
REDGPU_F_DECLSPEC void                redFDirectoryAllowExt                   (RedFHandleDirectory handle, const char * extension);
REDGPU_F_DECLSPEC void                redFDirectoryGetOriginalDirectory       (RedFHandleDirectory handle, char ** outOriginalDirectory, uint64_t * outOriginalDirectoryBytesCount); // redFFree() outOriginalDirectory[0] yourself
REDGPU_F_DECLSPEC void                redFDirectoryGetName                    (RedFHandleDirectory handle, uint64_t index, char ** outName, uint64_t * outNameBytesCount); // redFFree() outName[0] yourself
REDGPU_F_DECLSPEC void                redFDirectoryGetPath                    (RedFHandleDirectory handle, uint64_t index, char ** outPath, uint64_t * outPathBytesCount); // redFFree() outPath[0] yourself
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetShowHidden              (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC void                redFDirectoryReset                      (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC void                redFDirectorySort                       (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC void                redFDirectorySortByDate                 (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC uint64_t            redFDirectorySize                       (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC uint64_t            redFDirectoryGetFileCount               (RedFHandleDirectory handle);
REDGPU_F_DECLSPEC void                redFDirectoryGetFilePath                (RedFHandleDirectory handle, uint64_t index, char ** outPath, uint64_t * outPathBytesCount); // redFFree() outPath[0] yourself
REDGPU_F_DECLSPEC void                redFDirectoryGetFileExtension           (RedFHandleDirectory handle, uint64_t index, char ** outExtension, uint64_t * outExtensionBytesCount); // redFFree() outExtension[0] yourself
REDGPU_F_DECLSPEC void                redFDirectoryGetFileName                (RedFHandleDirectory handle, uint64_t index, char ** outFileName, uint64_t * outFileNameBytesCount); // redFFree() outFileName[0] yourself
REDGPU_F_DECLSPEC void                redFDirectoryGetFileBaseName            (RedFHandleDirectory handle, uint64_t index, char ** outBaseName, uint64_t * outBaseNameBytesCount); // redFFree() outBaseName[0] yourself
REDGPU_F_DECLSPEC void                redFDirectoryGetFileEnclosingDirectory  (RedFHandleDirectory handle, uint64_t index, char ** outEnclosingDirectory, uint64_t * outEnclosingDirectoryBytesCount); // redFFree() outEnclosingDirectory[0] yourself
REDGPU_F_DECLSPEC void                redFDirectoryGetFileAbsolutePath        (RedFHandleDirectory handle, uint64_t index, char ** outAbsolutePath, uint64_t * outAbsolutePathBytesCount); // redFFree() outAbsolutePath[0] yourself
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetFileCanRead             (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetFileCanWrite            (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetFileCanExecute          (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetFileIsFile              (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetFileIsLink              (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetFileIsDirectory         (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetFileIsDevice            (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC RedFBool32          redFDirectoryGetFileIsHidden            (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC uint64_t            redFDirectoryGetFileGetSize             (RedFHandleDirectory handle, uint64_t index);
REDGPU_F_DECLSPEC RedFBool32          redFCreateDirectoryPath                 (const char * dirPath, RedFBool32 bRelativeToDataDefaultIs1, RedFBool32 recursiveDefaultIs0);
REDGPU_F_DECLSPEC RedFBool32          redFIsDirectoryEmpty                    (const char * dirPath, RedFBool32 bRelativeToDataDefaultIs1);
REDGPU_F_DECLSPEC RedFBool32          redFDoesDirectoryExist                  (const char * dirPath, RedFBool32 bRelativeToDataDefaultIs1);
REDGPU_F_DECLSPEC RedFBool32          redFRemoveDirectory                     (const char * dirPath, RedFBool32 deleteIfNotEmpty, RedFBool32 bRelativeToDataDefaultIs1);
REDGPU_F_DECLSPEC RedFBool32          redFCopyFileFromTo                      (const char * pathSrc, const char * pathDst, RedFBool32 bRelativeToDataDefaultIs1, RedFBool32 overwriteDefaultIs0);
REDGPU_F_DECLSPEC RedFBool32          redFMoveFileFromTo                      (const char * pathSrc, const char * pathDst, RedFBool32 bRelativeToDataDefaultIs1, RedFBool32 overwriteDefaultIs0);
REDGPU_F_DECLSPEC RedFBool32          redFDoesFileExist                       (const char * path, RedFBool32 bRelativeToDataDefaultIs1);
REDGPU_F_DECLSPEC RedFBool32          redFRemoveFile                          (const char * path, RedFBool32 bRelativeToDataDefaultIs1);
REDGPU_F_DECLSPEC void                redFGetCurrentWorkingDirectory          (char ** outPath, uint64_t * outPathBytesCount); // redFFree() outPath[0] yourself
REDGPU_F_DECLSPEC void                redFGetCurrentExeDir                    (char ** outPath, uint64_t * outPathBytesCount); // redFFree() outPath[0] yourself
REDGPU_F_DECLSPEC void                redFGetCurrentExePath                   (char ** outPath, uint64_t * outPathBytesCount); // redFFree() outPath[0] yourself
REDGPU_F_DECLSPEC void                redFGetUserHomeDir                      (char ** outPath, uint64_t * outPathBytesCount); // redFFree() outPath[0] yourself

REDGPU_F_DECLSPEC RedFHandleThread *  redFCreateThread                        (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyThread                       (RedFHandleThread * handles);
REDGPU_F_DECLSPEC RedFBool32          redFThreadIsRunning                     (RedFHandleThread handle);
REDGPU_F_DECLSPEC void                redFThreadGetName                       (RedFHandleThread handle, char ** outName, uint64_t * outNameBytesCount); // redFFree() outName[0] yourself
REDGPU_F_DECLSPEC void                redFThreadSetName                       (RedFHandleThread handle, const char * name);
REDGPU_F_DECLSPEC void                redFThreadStart                         (RedFHandleThread handle);
REDGPU_F_DECLSPEC RedFBool32          redFThreadLock                          (RedFHandleThread handle);
REDGPU_F_DECLSPEC RedFBool32          redFThreadTryLock                       (RedFHandleThread handle);
REDGPU_F_DECLSPEC void                redFThreadUnlock                        (RedFHandleThread handle);
REDGPU_F_DECLSPEC void                redFThreadStop                          (RedFHandleThread handle);
REDGPU_F_DECLSPEC void                redFThreadWaitFor                       (RedFHandleThread handle, RedFBool32 callStopThreadDefaultIs1, long millisecondsDefaultIsMinus1ForInfiniteJoinTimeout);
REDGPU_F_DECLSPEC void                redFThreadSleep                         (RedFHandleThread handle, long milliseconds);
REDGPU_F_DECLSPEC void                redFThreadYield                         (RedFHandleThread handle);
REDGPU_F_DECLSPEC RedFBool32          redFThreadIsCurrent                     (RedFHandleThread handle);

REDGPU_F_DECLSPEC RedFHandleThreadChannel * redFCreateThreadChannel           (uint64_t count);
REDGPU_F_DECLSPEC void                redFDestroyThreadChannel                (RedFHandleThreadChannel * handles);
REDGPU_F_DECLSPEC RedFBool32          redFThreadChannelSend                   (RedFHandleThreadChannel handle, void * value);
REDGPU_F_DECLSPEC RedFBool32          redFThreadChannelReceive                (RedFHandleThreadChannel handle, void ** outSentValue);
REDGPU_F_DECLSPEC RedFBool32          redFThreadChannelTryReceive             (RedFHandleThreadChannel handle, void ** outSentValue);
REDGPU_F_DECLSPEC RedFBool32          redFThreadChannelTryReceiveWithTimeout  (RedFHandleThreadChannel handle, void ** outSentValue, int64_t timeoutMs);
REDGPU_F_DECLSPEC RedFBool32          redFThreadChannelEmpty                  (RedFHandleThreadChannel handle);
REDGPU_F_DECLSPEC void                redFThreadChannelClose                  (RedFHandleThreadChannel handle);

REDGPU_F_DECLSPEC RedFBool32          redFEventParametersKeyHasModifier       (RedFHandleEventParametersKey parameters, int modifier);
REDGPU_F_DECLSPEC unsigned            redFEventParametersKeyGetCodepoint      (RedFHandleEventParametersKey parameters);
REDGPU_F_DECLSPEC RedFBool32          redFEventParametersKeyIsRepeat          (RedFHandleEventParametersKey parameters);
REDGPU_F_DECLSPEC int                 redFEventParametersKeyGetKey            (RedFHandleEventParametersKey parameters);
REDGPU_F_DECLSPEC int                 redFEventParametersKeyGetKeycode        (RedFHandleEventParametersKey parameters);
REDGPU_F_DECLSPEC int                 redFEventParametersKeyGetModifiers      (RedFHandleEventParametersKey parameters);
REDGPU_F_DECLSPEC int                 redFEventParametersKeyGetScancode       (RedFHandleEventParametersKey parameters);
REDGPU_F_DECLSPEC RedFKeyEventType    redFEventParametersKeyGetEventType      (RedFHandleEventParametersKey parameters);
REDGPU_F_DECLSPEC RedFBool32          redFEventParametersMouseHasModifier     (RedFHandleEventParametersMouse parameters, int modifier);
REDGPU_F_DECLSPEC float               redFEventParametersMouseGetX            (RedFHandleEventParametersMouse parameters);
REDGPU_F_DECLSPEC float               redFEventParametersMouseGetY            (RedFHandleEventParametersMouse parameters);
REDGPU_F_DECLSPEC int                 redFEventParametersMouseGetButton       (RedFHandleEventParametersMouse parameters);
REDGPU_F_DECLSPEC int                 redFEventParametersMouseGetModifiers    (RedFHandleEventParametersMouse parameters);
REDGPU_F_DECLSPEC float               redFEventParametersMouseGetScrollX      (RedFHandleEventParametersMouse parameters);
REDGPU_F_DECLSPEC float               redFEventParametersMouseGetScrollY      (RedFHandleEventParametersMouse parameters);
REDGPU_F_DECLSPEC RedFMouseEventType  redFEventParametersMouseGetEventType    (RedFHandleEventParametersMouse parameters);
REDGPU_F_DECLSPEC int                 redFEventParametersResizeGetWidth       (RedFHandleEventParametersResize parameters);
REDGPU_F_DECLSPEC int                 redFEventParametersResizeGetHeight      (RedFHandleEventParametersResize parameters);
REDGPU_F_DECLSPEC uint64_t            redFEventParametersDragGetFilesCount    (RedFHandleEventParametersDrag parameters);
REDGPU_F_DECLSPEC const char *        redFEventParametersDragGetFile          (RedFHandleEventParametersDrag parameters, uint64_t fileIndex);
REDGPU_F_DECLSPEC void                redFEventParametersDragGetFileW         (RedFHandleEventParametersDrag parameters, uint64_t fileIndex, wchar_t ** outPath, uint64_t * outPathBytesCount); // redFFree() outPath[0] yourself
REDGPU_F_DECLSPEC float               redFEventParametersDragGetPositionX     (RedFHandleEventParametersDrag parameters);
REDGPU_F_DECLSPEC float               redFEventParametersDragGetPositionY     (RedFHandleEventParametersDrag parameters);

REDGPU_F_DECLSPEC RedFBool32          redFGetMousePressed                     (int button);
REDGPU_F_DECLSPEC int                 redFGetMouseX                           (void);
REDGPU_F_DECLSPEC int                 redFGetMouseY                           (void);
REDGPU_F_DECLSPEC int                 redFGetPreviousMouseX                   (void);
REDGPU_F_DECLSPEC int                 redFGetPreviousMouseY                   (void);
REDGPU_F_DECLSPEC void                redFPushMatrix                          (void);
REDGPU_F_DECLSPEC void                redFMultMatrix                          (void * mat4);
REDGPU_F_DECLSPEC void                redFMultViewMatrix                      (void * mat4);
REDGPU_F_DECLSPEC void                redFScale                               (float x, float y, float z);
REDGPU_F_DECLSPEC void                redFRotateDeg                           (float degrees, float axisX, float axisY, float axisZ);
REDGPU_F_DECLSPEC void                redFTranslate                           (float x, float y, float z);
REDGPU_F_DECLSPEC void                redFPopMatrix                           (void);
REDGPU_F_DECLSPEC void                redFSetMatrixMode                       (RedFMatrixMode matrixMode);
REDGPU_F_DECLSPEC void                redFLoadMatrix                          (void * mat4);
REDGPU_F_DECLSPEC void                redFLoadViewMatrix                      (void * mat4);
REDGPU_F_DECLSPEC void                redFPushView                            (void);
REDGPU_F_DECLSPEC void                redFPopView                             (void);
REDGPU_F_DECLSPEC void                redFPushStyle                           (void);
REDGPU_F_DECLSPEC void                redFBackground                          (int r, int g, int b, int a);
REDGPU_F_DECLSPEC void                redFFill                                (void);
REDGPU_F_DECLSPEC void                redFNoFill                              (void);
REDGPU_F_DECLSPEC void                redFSetColor                            (int r, int g, int b, int a);
REDGPU_F_DECLSPEC void                redFSetLineWidth                        (float width);
REDGPU_F_DECLSPEC void                redFPopStyle                            (void);
REDGPU_F_DECLSPEC void                redFDrawTriangle                        (float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2);
REDGPU_F_DECLSPEC void                redFDrawSphere                          (float x, float y, float z, float radius);
REDGPU_F_DECLSPEC void                redFDrawPoint                           (float x, float y, float z, float radius, RedFHandleCamera camera);
REDGPU_F_DECLSPEC void                redFDrawBox                             (float x, float y, float z, float width, float height, float depth);
REDGPU_F_DECLSPEC void                redFDrawPlane                           (float x, float y, float z, float width, float height);
REDGPU_F_DECLSPEC void                redFDrawBoxPrimitive                    (float x, float y, float z, float qx, float qy, float qz, float qw, float width, float height, float depth, int resWidth, int resHeight, int resDepth, RedFBool32 wireframe, int r, int g, int b, int a);
REDGPU_F_DECLSPEC void                redFDrawPlanePrimitive                  (float x, float y, float z, float qx, float qy, float qz, float qw, float width, float height, int resWidth, int resHeight, RedFBool32 wireframe);
REDGPU_F_DECLSPEC void                redFGetBoxPrimitiveMesh                 (float width, float height, float depth, int resWidth, int resHeight, int resDepth, RedFHandleMesh replaceMesh);
REDGPU_F_DECLSPEC void                redFGetPlanePrimitiveMesh               (float width, float height, int resWidth, int resHeight, RedFHandleMesh replaceMesh);
REDGPU_F_DECLSPEC void                redFDrawLine                            (float x0, float y0, float z0, float x1, float y1, float z1);
REDGPU_F_DECLSPEC void                redFDrawCircle                          (float x, float y, float z, float radius);
REDGPU_F_DECLSPEC void                redFDrawRectangle                       (float x, float y, float z, float w, float h);
REDGPU_F_DECLSPEC void                redFDrawRectRounded                     (float x, float y, float z, float w, float h, float topLeftRadius, float topRightRadius, float bottomRightRadius, float bottomLeftRadius);
REDGPU_F_DECLSPEC void                redFDrawCurve                           (float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
REDGPU_F_DECLSPEC void                redFDrawBezier                          (float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
REDGPU_F_DECLSPEC void                redFDrawBitmapString                    (const char * string, float x, float y, float z);
REDGPU_F_DECLSPEC void                redFDrawBitmapStringHighlight           (const char * string, float x, float y, float z, int bgR, int bgG, int bgB, int bgA, int fgR, int fgG, int fgB, int fgA);
REDGPU_F_DECLSPEC void                redFDrawBitmapStringHighlightFromCamera (const char * string, float x, float y, float z, int bgR, int bgG, int bgB, int bgA, int fgR, int fgG, int fgB, int fgA, RedFHandleCamera camera);
REDGPU_F_DECLSPEC void                redFEnableAlphaBlending                 (void);
REDGPU_F_DECLSPEC void                redFDisableAlphaBlending                (void);
REDGPU_F_DECLSPEC void                redFEnableAntiAliasing                  (void);
REDGPU_F_DECLSPEC void                redFDisableAntiAliasing                 (void);
REDGPU_F_DECLSPEC void                redFEnableBlendMode                     (RedFBlendMode blendMode);
REDGPU_F_DECLSPEC void                redFDisableBlendMode                    (void);
REDGPU_F_DECLSPEC void                redFEnableDepthTest                     (void);
REDGPU_F_DECLSPEC void                redFDisableDepthTest                    (void);
REDGPU_F_DECLSPEC void                redFGetClipboardStringChars             (char ** outString, uint64_t * outStringBytesCount); // redFFree() outString[0] yourself
REDGPU_F_DECLSPEC void                redFSetClipboardString                  (const char * string);
REDGPU_F_DECLSPEC void                redFShowCursor                          (void);
REDGPU_F_DECLSPEC void                redFHideCursor                          (void);
REDGPU_F_DECLSPEC unsigned long       redFGetX11Window                        (void);
REDGPU_F_DECLSPEC void *              redFGetX11Display                       (void);
REDGPU_F_DECLSPEC void                redFSetFrameRate                        (int targetRate);
REDGPU_F_DECLSPEC void                redFSetVerticalSync                     (RedFBool32 sync);
REDGPU_F_DECLSPEC void                redFSetFullscreen                       (RedFBool32 fullscreen);
REDGPU_F_DECLSPEC int                 redFGetWidth                            (void);
REDGPU_F_DECLSPEC int                 redFGetHeight                           (void);
REDGPU_F_DECLSPEC RedFBool32          redFIsVFlipped                          (void);
REDGPU_F_DECLSPEC float               redFGetNativeViewportX                  (void);
REDGPU_F_DECLSPEC float               redFGetNativeViewportY                  (void);
REDGPU_F_DECLSPEC float               redFGetNativeViewportWidth              (void);
REDGPU_F_DECLSPEC float               redFGetNativeViewportHeight             (void);
REDGPU_F_DECLSPEC void                redFViewport                            (float x, float y, float width, float height, RedFBool32 vFlip);
REDGPU_F_DECLSPEC void                redFColorMask                           (RedFBool32 r, RedFBool32 g, RedFBool32 b, RedFBool32 a);
REDGPU_F_DECLSPEC void                redFClear                               (float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFClearAlpha                          (void);
REDGPU_F_DECLSPEC void                redFEnableLighting                      (void);
REDGPU_F_DECLSPEC void                redFDisableLighting                     (void);
REDGPU_F_DECLSPEC RedFBool32          redFGetLightingEnabled                  (void);
REDGPU_F_DECLSPEC void                redFEnableSeparateSpecularLight         (void);
REDGPU_F_DECLSPEC void                redFDisableSeparateSpecularLight        (void);
REDGPU_F_DECLSPEC void                redFSetGlobalAmbientColor               (float r, float g, float b, float a);
REDGPU_F_DECLSPEC void                redFGetGlobalAmbientColor               (void * outVec4);
REDGPU_F_DECLSPEC void                redFSetSmoothLighting                   (RedFBool32 enable);
REDGPU_F_DECLSPEC void                redFEnableCulling                       (unsigned modeDefaultIsGLBack0x0405);
REDGPU_F_DECLSPEC void                redFDisableCulling                      (void);
REDGPU_F_DECLSPEC float               redFGetElapsedTimef                     (void);
REDGPU_F_DECLSPEC uint64_t            redFGetElapsedTimeMillis                (void);
REDGPU_F_DECLSPEC uint64_t            redFGetElapsedTimeMicros                (void);
REDGPU_F_DECLSPEC void                redFResetElapsedTimeCounter             (void);
REDGPU_F_DECLSPEC double              redFGetLastFrameTime                    (void);
REDGPU_F_DECLSPEC uint64_t            redFGetSystemTimeMillis                 (void);
REDGPU_F_DECLSPEC uint64_t            redFGetSystemTimeMicros                 (void);
REDGPU_F_DECLSPEC unsigned            redFGetUnixTime                         (void);
REDGPU_F_DECLSPEC void                redFDisableArbTex                       (void);
REDGPU_F_DECLSPEC void                redFEnableArbTex                        (void);
REDGPU_F_DECLSPEC void                redFGetEnv                              (const char * variable, char ** outValue, uint64_t * outValueBytesCount); // redFFree() outValue[0] yourself
REDGPU_F_DECLSPEC void                redFSystem                              (const char * command, char ** outOutput, uint64_t * outOutputBytesCount); // redFFree() outOutput[0] yourself
REDGPU_F_DECLSPEC void                redFSystemAlertDialog                   (const char * errorMessage);
REDGPU_F_DECLSPEC RedFBool32          redFSystemLoadDialog                    (const char * windowTitle, RedFBool32 bFolderSelection, const char * defaultPath, char ** outFilePath, uint64_t * outFilePathBytesCount, char ** outFileName, uint64_t * outFileNameBytesCount); // redFFree() outFilePath[0] and outFileName[0] yourself
REDGPU_F_DECLSPEC RedFBool32          redFSystemSaveDialog                    (const char * defaultName, const char * messageName, char ** outFilePath, uint64_t * outFilePathBytesCount, char ** outFileName, uint64_t * outFileNameBytesCount); // redFFree() outFilePath[0] and outFileName[0] yourself
REDGPU_F_DECLSPEC void                redFSystemTextBoxDialog                 (const char * question, const char * text, char ** outAnswer, uint64_t * outAnswerBytesCount); // redFFree() outAnswer[0] yourself
REDGPU_F_DECLSPEC void                redFFree                                (void * pointer);

#ifdef __cplusplus
}
#endif
