#include <iostream>

int odyssey_physics_main(int argc, char* argv[]);
int odyssey_gym_main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <mode>\n", argv[0]);
        printf("mode: 0 - odyssey-physics, 1 - odyssey-gym\n");
        return 1;
    }

    int mode = atoi(argv[1]);
    if (mode == 0) {
        return odyssey_physics_main(argc-2, argv+2);
    } else if (mode == 1) {
        //return odyssey_gym_main(argc-2, argv+2);
        return -1;
    } else {
        printf("Invalid mode: %d\n", mode);
        return 1;
    }
}
