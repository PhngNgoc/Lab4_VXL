/*
 * display7seg.c
 *
 *  Created on: Oct 28, 2024
 *      Author: tranm
 */

#include "display7seg.h"

uint8_t change_displaynumber(int num){
    if (num == 0 ) return 0b01000000;
    if (num == 1 ) return 0b11111001;
    if (num == 2 ) return 0b00100100;
    if (num == 3 ) return 0b00110000;
    if (num == 4 ) return 0b00011001;
    if (num == 5 ) return 0b00010010;
    if (num == 6 ) return 0b00000010;
    if (num == 7 ) return 0b01111000;
    if (num == 8 ) return 0b00000000;
    if (num == 9 ) return 0b00010000;
    return 0b01111111;
}

void displayled_3and4( int num3, int num4) {
    uint8_t data3 = change_displaynumber(num3);
    uint8_t data4 = change_displaynumber(num4);
    for (int i = 0; i < 8; i++) {
           if ( data3 & (0x80 >> i)) {
               HAL_GPIO_WritePin(led7_3_GPIO_Port, led7_3_Pin, GPIO_PIN_SET);
           } else {
               HAL_GPIO_WritePin(led7_3_GPIO_Port, led7_3_Pin, GPIO_PIN_RESET);
           }
           if ( data4 & (0x80 >> i)) {
               HAL_GPIO_WritePin(led7_4_GPIO_Port, led7_4_Pin, GPIO_PIN_SET);
           } else {
               HAL_GPIO_WritePin(led7_4_GPIO_Port, led7_4_Pin, GPIO_PIN_RESET);
           }
           // Tạo xung trên SH_CP để dịch bit vào thanh ghi
           HAL_GPIO_WritePin(SH_CP_GPIO_Port, SH_CP_Pin, GPIO_PIN_SET);
           HAL_GPIO_WritePin(SH_CP_GPIO_Port, SH_CP_Pin, GPIO_PIN_RESET);
       }

       // Tạo xung trên ST_CP để chốt dữ liệu sau khi đã dịch xong 8 bit
       HAL_GPIO_WritePin( ST_CP_GPIO_Port, ST_CP_Pin, GPIO_PIN_SET);
       HAL_GPIO_WritePin(ST_CP_GPIO_Port, ST_CP_Pin, GPIO_PIN_RESET);

}


void display7SEG1(int num){
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
			break;
	}
}
void display7SEG2(int num){
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, RESET);
			break;
	}
}

