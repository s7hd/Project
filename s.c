#include <stdio.h>

int RA = 0, RB = 1, RO = 0;
int PC = 0;   
int JC = 0;   
int instructions[10]; 

void printRegisters() {
    printf("RA=%d, RB=%d, RO=%d, PC=%d\n", RA, RB, RO, PC);
}

void stepByStepMode() {
    printf("Starting Simulator in step-by-step mode...\n");
    while (PC < 10) {
        printf("Instruction %d: [Press Enter to continue]", PC);
        getchar(); 

        switch (PC) {
            case 0:
                RA = 0;
                printf("RA=%d\n", RA);
                break;
            case 1:
                RB = 1;
                printf("RB=%d\n", RB);
                break;
            case 2:
                RO = RA;
                printf("RO=%d (RO=RA)\n", RO);
                break;
            case 3:
                RB = RA + RB;
                printf("RB=%d (RB=RA+RB)\n", RB);
                break;
            case 4:
                if (RA + RB > 15) { 
                    JC = 1;
                    printf("JC set to %d (carry detected)\n", JC);
                } else {
                    JC = 0;
                    printf("JC=%d (No carry)\n", JC);
                }
                break;
            case 5:
                RA = RA + RB;
                printf("RA=%d (RA=RA+RB)\n", RA);
                break;
            case 6:
                RB = RA - RB;
                printf("RB=%d (RB=RA-RB)\n", RB);
                break;
            case 7:
                RA = RA - RB;
                printf("RA=%d (RA=RA-RB)\n", RA);
                break;
            case 8:
                if (JC == 0) {
                    if (RO == 13) { 
                        RA = 0;
                        RB = 1;
                        printf("Resetting RA and RB for new Fibonacci sequence\n");
                    }
                    PC = 2; 
                    printf("Jump to instruction %d\n", PC);
                    continue;
                }
                break;
            default:
                printf("End of instructions.\n");
                return;
        }
        printRegisters();
        PC++; 
    }
}

void continuousMode() {
    printf("Starting Simulator in continuous mode...\n");
    while (PC < 10) {
        switch (PC) {
            case 0:
                RA = 0;
                break;
            case 1:
                RB = 1;
                break;
            case 2:
                RO = RA;
                printf("RO=%d (RO=RA)\n", RO);
                break;
            case 3:
                RB = RA + RB;
                break;
            case 4:
                if (RA + RB > 15) {  
                    JC = 1;
                } else {
                    JC = 0;
                }
                break;
            case 5:
                RA = RA + RB;
                break;
            case 6:
                RB = RA - RB;
                break;
            case 7:
                RA = RA - RB;
                break;
            case 8:
                if (JC == 0) {
                    if (RO == 13) {
                        RA = 0;
                        RB = 1;
                        printf("Resetting RA and RB for new Fibonacci sequence\n");
                    }
                    PC = 2; 
                    continue;
                }
                break;
            default:
                printf("End of instructions.\n");
                return;
        }
        if (PC == 2) {
            printf("RO=%d\n", RO); }
        PC++; 
    }
}

int main() {
    char mode;
    printf("Select mode: R (Run continuously) or S (Step-by-step): ");
    scanf(" %c", &mode);
    getchar(); 

    if (mode == 'S' || mode == 's') {
        stepByStepMode();
    } else if (mode == 'R' || mode == 'r') {
        continuousMode();
    } else {
        printf("Invalid mode selected.\n");
    }

    return 0;
}
