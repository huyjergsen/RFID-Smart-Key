#include "keypad.h"
#define C1_PIN GPIO_PIN_9
#define C2_PIN GPIO_PIN_10
#define C3_PIN GPIO_PIN_11
#define C4_PIN GPIO_PIN_12
#define C_PORT GPIOA

#define R1_PIN GPIO_PIN_4
#define R2_PIN GPIO_PIN_5
#define R3_PIN GPIO_PIN_6
#define R4_PIN GPIO_PIN_7
#define R_PORT GPIOD


/* Map phím 4x4 */
const char Keypad_Map[4][4] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

/* Khởi tạo keypad (không cần nếu đã cấu hình GPIO trong CubeIDE) */
void Keypad_Init(void)
{
    for (int i = 0; i < 4; i++)
    {
        HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], GPIO_PIN_SET); // ROW = HIGH
    }
}

char Keypad_GetKey(void)
{
    for (int row = 0; row < 4; row++)
    {
        /* Kéo hàng hiện tại xuống LOW */
        HAL_GPIO_WritePin(ROW_PORT[row], ROW_PIN[row], GPIO_PIN_RESET);

        for (int col = 0; col < 4; col++)
        {
            if (HAL_GPIO_ReadPin(COL_PORT[col], COL_PIN[col]) == GPIO_PIN_RESET)
            {
                HAL_Delay(40);  // chống dội phím

                /* Chờ nhả phím */
                while (HAL_GPIO_ReadPin(COL_PORT[col], COL_PIN[col]) == GPIO_PIN_RESET);

                HAL_GPIO_WritePin(ROW_PORT[row], ROW_PIN[row], GPIO_PIN_SET);

                return Keypad_Map[row][col];
            }
        }

        /* Trả ROW lại HIGH */
        HAL_GPIO_WritePin(ROW_PORT[row], ROW_PIN[row], GPIO_PIN_SET);
    }

    return 0; // không nhấn gì
}
