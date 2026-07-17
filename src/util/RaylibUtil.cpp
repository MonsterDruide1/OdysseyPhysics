#include "RaylibUtil.h"

Mesh cubeMesh;
Model cubeModel;
Mesh sphereMesh;
Model sphereModel;
Shader checkerShader;

void setupRaylibUtil() {
    cubeMesh = GenMeshCube(50, 50, 50);
    cubeModel = LoadModelFromMesh(cubeMesh);
    sphereMesh = GenMeshSphere(50, 16, 16);
    sphereModel = LoadModelFromMesh(sphereMesh);
    checkerShader = LoadShader("res/shaders/gles310/normal.vs", "res/shaders/gles310/normal.fs");
}

void unloadRaylibUtil() {
    UnloadShader(checkerShader);
    UnloadMesh(cubeMesh);
}
