#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

static const float VELOCITY = 0.5;

void HandleMovement(Camera3D* camera)
{
    if (IsKeyDown(KEY_W)) {
        MoveCameraTowards(camera, camera->target);
    }
    if (IsKeyDown(KEY_S)) {
        MoveCameraTowards(camera, Vector3Invert(camera->target));
    }
    if (IsKeyDown(KEY_A)) {
        MoveCameraTowards(camera, Vector3Invert(camera->target));
    }
    if (IsKeyDown(KEY_D)) {
        camera->position.y -= VELOCITY;
    }
}

void MoveCameraTowards(Camera3D* camera, Vector3 towards)
{
    camera->position = Vector3MoveTowards(camera->position, towards, VELOCITY);
}

int main()
{
    InitWindow(800, 600, "Olá mundo!");
    SetTargetFPS(60);
    Camera3D camera;
    camera.position = (Vector3) { 0, 10, 10 };
    camera.up = (Vector3) { 0, 1, 0 };
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cube_origin = (Vector3) { 0, 0, 0 };

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        BeginMode3D(camera);

        UpdateCamera(&camera, CAMERA_FREE);

        DrawGrid(100, 5);

        DrawCube(cube_origin, 5, 5, 5, RED);

        EndMode3D();

        char fps[3];
        sprintf(&fps, "%d", GetFPS());
        DrawText(fps, 10, 10, 20, BLACK);

        DrawText("Congrats! You created your first window!", 190, 200, 20,
            BLACK);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
