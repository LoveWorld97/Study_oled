#include "oled.h"
#include "main.h"

typFNT_ASC16 ASC_16[] =
    {
        {"0", {0x00, 0xE0, 0x10, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x0F, 0x10, 0x20, 0x20, 0x10, 0x0F, 0x00}}, //"0"

        {"1", {0x00, 0x00, 0x10, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00}}, //"1"

        {"2", {0x00, 0x70, 0x08, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x00, 0x30, 0x28, 0x24, 0x22, 0x21, 0x30, 0x00}}, //"2"

        {"3", {0x00, 0x30, 0x08, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x18, 0x20, 0x21, 0x21, 0x22, 0x1C, 0x00}}, //"3"

        {"4", {0x00, 0x00, 0x80, 0x40, 0x30, 0xF8, 0x00, 0x00, 0x00, 0x06, 0x05, 0x24, 0x24, 0x3F, 0x24, 0x24}}, //"4"

        {"5", {0x00, 0xF8, 0x88, 0x88, 0x88, 0x08, 0x08, 0x00, 0x00, 0x19, 0x20, 0x20, 0x20, 0x11, 0x0E, 0x00}}, //"5"

        {"6", {0x00, 0xE0, 0x10, 0x88, 0x88, 0x90, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x20, 0x20, 0x20, 0x1F, 0x00}}, //"6"

        {"7", {0x00, 0x18, 0x08, 0x08, 0x88, 0x68, 0x18, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x01, 0x00, 0x00, 0x00}}, //"7"

        {"8", {0x00, 0x70, 0x88, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x1C, 0x22, 0x21, 0x21, 0x22, 0x1C, 0x00}}, //"8"

        {"9", {0x00, 0xF0, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x01, 0x12, 0x22, 0x22, 0x11, 0x0F, 0x00}}, //"9"

        {"a", {0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x19, 0x24, 0x24, 0x12, 0x3F, 0x20, 0x00}}, /*"a"*/

        {"b", {0x10, 0xF0, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x11, 0x20, 0x20, 0x11, 0x0E, 0x00}}, /*"b"*/

        {"c", {0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x20, 0x20, 0x20, 0x11, 0x00}}, /*"c"*/

        {"d", {0x00, 0x00, 0x80, 0x80, 0x80, 0x90, 0xF0, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x10, 0x3F, 0x20}}, /*"d"*/

        {"e", {0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1F, 0x24, 0x24, 0x24, 0x24, 0x17, 0x00}}, /*"e"*/

        {"f", {0x00, 0x80, 0x80, 0xE0, 0x90, 0x90, 0x20, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00}}, /*"f"*/

        {"g", {0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x6B, 0x94, 0x94, 0x94, 0x93, 0x60, 0x00}}, /*"g"*/

        {"h", {0x10, 0xF0, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x3F, 0x21, 0x00, 0x00, 0x20, 0x3F, 0x20}}, /*"h"*/

        {"i", {0x00, 0x80, 0x98, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00}}, /*"i"*/

        {"j", {0x00, 0x00, 0x00, 0x80, 0x98, 0x98, 0x00, 0x00, 0x00, 0xC0, 0x80, 0x80, 0x80, 0x7F, 0x00, 0x00}}, /*"j"*/

        {"k", {0x10, 0xF0, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x20, 0x3F, 0x24, 0x06, 0x29, 0x30, 0x20, 0x00}}, /*"k"*/

        {"l", {0x00, 0x10, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00}}, /*"l"*/

        {"m", {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x3F, 0x20, 0x00, 0x3F}}, /*"m"*/

        {"n", {0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x3F, 0x21, 0x00, 0x00, 0x20, 0x3F, 0x20}}, /*"n"*/

        {"o", {0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x20, 0x1F, 0x00}}, /*"o"*/

        {"p", {0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x91, 0x20, 0x20, 0x11, 0x0E, 0x00}}, /*"p"*/

        {"q", {0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x0E, 0x11, 0x20, 0x20, 0x91, 0xFF, 0x80}}, /*"q"*/

        {"r", {0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x20, 0x20, 0x3F, 0x21, 0x20, 0x00, 0x01, 0x00}}, /*"r"*/

        {"s", {0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x33, 0x24, 0x24, 0x24, 0x24, 0x19, 0x00}}, /*"s"*/

        {"t", {0x00, 0x80, 0x80, 0xE0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x10, 0x00}}, /*"t"*/

        {"u", {0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x10, 0x3F, 0x20}}, /*"u"*/

        {"v", {0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x03, 0x0C, 0x30, 0x0C, 0x03, 0x00, 0x00}}, /*"v"*/

        {"w", {0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x01, 0x0E, 0x30, 0x0C, 0x07, 0x38, 0x06, 0x01}}, /*"w"*/

        {"x", {0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x20, 0x31, 0x0E, 0x2E, 0x31, 0x20, 0x00}}, /*"x"*/

        {"y", {0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x81, 0x86, 0x78, 0x18, 0x06, 0x01, 0x00}}, /*"y"*/

        {"z", {0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x21, 0x30, 0x2C, 0x22, 0x21, 0x30, 0x00}}, /*"z"*/

        {":", {0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00}}, /*":"*/

        {".", {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00}}, /*"."*/
};
/***************************16*16的点阵字体取模方式：共阴——列行式——逆向输出*********/
typFNT_GB16 GB_16[] =
    {
        {"高", {0x04, 0x04, 0x04, 0x04, 0xF4, 0x94, 0x95, 0x96, 0x94, 0x94, 0xF4, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0xFE, 0x02, 0x02, 0x7A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x7A, 0x02, 0x82, 0xFE, 0x00, 0x00}}, /*高*/

        {"凯", {0x5E, 0x50, 0x50, 0x5F, 0x50, 0x50, 0xDE, 0x00, 0xFE, 0x02, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x42, 0x22, 0x22, 0x12, 0x93, 0x60, 0x1F, 0x00, 0x00, 0x3F, 0x40, 0x40, 0x78, 0x00}}, /*凯*/

        {"琦", {0x84, 0x84, 0xFC, 0x84, 0x84, 0x40, 0x64, 0x54, 0x4C, 0x47, 0x4C, 0x54, 0xE4, 0x44, 0x40, 0x00, 0x10, 0x30, 0x1F, 0x08, 0x08, 0x00, 0x1F, 0x11, 0x11, 0x1F, 0x40, 0x80, 0x7F, 0x00, 0x00, 0x00}}, /*琦*/

        {"加", {0x10, 0x10, 0x10, 0xFF, 0x10, 0x10, 0xF0, 0x00, 0x00, 0xF8, 0x08, 0x08, 0x08, 0xF8, 0x00, 0x00, 0x80, 0x40, 0x30, 0x0F, 0x40, 0x80, 0x7F, 0x00, 0x00, 0x7F, 0x20, 0x20, 0x20, 0x7F, 0x00, 0x00}}, /*加*/

        {"油", {0x10, 0x60, 0x02, 0x8C, 0x00, 0xF0, 0x10, 0x10, 0x10, 0xFF, 0x10, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x04, 0x04, 0x7E, 0x01, 0x00, 0xFF, 0x42, 0x42, 0x42, 0x7F, 0x42, 0x42, 0x42, 0xFF, 0x00, 0x00}}, /*油*/

        {"！", {0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}, /*！*/

        {"苏", {0x04, 0x44, 0x44, 0x44, 0x5F, 0x44, 0xF4, 0x44, 0x44, 0x44, 0x5F, 0xC4, 0x04, 0x04, 0x04, 0x00, 0x00, 0x10, 0x8E, 0x40, 0x20, 0x18, 0x07, 0x00, 0x40, 0x80, 0x40, 0x3F, 0x00, 0x01, 0x0E, 0x00}}, /*苏*/

        {"培", {0x20, 0x20, 0x20, 0xFF, 0x20, 0x20, 0x80, 0x94, 0xA4, 0x85, 0x86, 0xA4, 0x94, 0x84, 0x80, 0x00, 0x10, 0x30, 0x10, 0x0F, 0x08, 0x08, 0x00, 0xFC, 0x44, 0x44, 0x44, 0x44, 0x44, 0xFC, 0x00, 0x00}}, /*培*/

        {"佩", {0x80, 0x60, 0xF8, 0x07, 0x00, 0xFE, 0x02, 0x92, 0x92, 0xF2, 0x92, 0x92, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x80, 0x7F, 0x00, 0x1F, 0x00, 0xFF, 0x10, 0x1F, 0x00, 0x7F, 0xE0, 0x00}}, /*佩*/

        {"我", {0x20, 0x24, 0x24, 0x24, 0xFE, 0x23, 0x22, 0x20, 0x20, 0xFF, 0x20, 0x22, 0x2C, 0xA0, 0x20, 0x00, 0x00, 0x08, 0x48, 0x84, 0x7F, 0x02, 0x41, 0x40, 0x20, 0x13, 0x0C, 0x14, 0x22, 0x41, 0xF8, 0x00}}, /*我*/

        {"爱", {0x80, 0x64, 0x2C, 0x34, 0x24, 0x24, 0xEC, 0x32, 0x22, 0x22, 0x32, 0x2E, 0x23, 0xA2, 0x60, 0x00, 0x00, 0x41, 0x21, 0x91, 0x89, 0x87, 0x4D, 0x55, 0x25, 0x25, 0x55, 0x4D, 0x81, 0x80, 0x80, 0x00}}, /*爱*/

        {"你", {0x00, 0x80, 0x60, 0xF8, 0x07, 0x40, 0x20, 0x18, 0x0F, 0x08, 0xC8, 0x08, 0x08, 0x28, 0x18, 0x00, 0x01, 0x00, 0x00, 0xFF, 0x00, 0x10, 0x0C, 0x03, 0x40, 0x80, 0x7F, 0x00, 0x01, 0x06, 0x18, 0x00}}, /*你*/

};

void OLED_I2C_Write_Byte(unsigned char I2C_Dat, unsigned char OLED_TYPE)
{
    if (OLED_TYPE == OLED_CMD)
    {
        HAL_I2C_Mem_Write(&hi2c1, OLED0561_ADD, OLED_CMD, I2C_MEMADD_SIZE_8BIT, &I2C_Dat, 1, 100);
    }
    if (OLED_TYPE == OLED_DAT)
    {
        HAL_I2C_Mem_Write(&hi2c1, OLED0561_ADD, OLED_DAT, I2C_MEMADD_SIZE_8BIT, &I2C_Dat, 1, 100);
    }
}
/************************OLED_Init***************
    //注释只是对命令字节简单的介绍
    //关于初始化命令字节的详细描述，可以参考对应驱动芯片的数据手册
    //OLED模块初始�?
*/
void OLED_Init(void)
{

    OLED_I2C_Write_Byte(0xAE, OLED_CMD); //display off --- 关闭显示
    OLED_I2C_Write_Byte(0x00, OLED_CMD); //set lower column address --- 设置起始列地址的低四位�?00h~0Fh
    OLED_I2C_Write_Byte(0x10, OLED_CMD); //set higher column address --- 设置起始列地址的高四位�?10h~17h
    OLED_I2C_Write_Byte(0x40, OLED_CMD); //set display start line --- 设置起始行寄存器�?04h~7Fh
    OLED_I2C_Write_Byte(0xB0, OLED_CMD); //set page address --- 设置页地址，B0h~B7h
    OLED_I2C_Write_Byte(0x81, OLED_CMD); //set contrast control --- 设置对比�?
    OLED_I2C_Write_Byte(0x7F, OLED_CMD); //127�?01h~FFh
    OLED_I2C_Write_Byte(0xA1, OLED_CMD); //set segment remap --- 设置SEG重映射，A0h/A1h
    OLED_I2C_Write_Byte(0xA6, OLED_CMD); //normal display --- 即�?1”点亮像素点
                                         //A6h --- �?1”点亮像素点
                                         //A7h --- �?0”点亮像素点
    OLED_I2C_Write_Byte(0xA8, OLED_CMD); //set multiplex ratio --- 设置多路复用�?
    OLED_I2C_Write_Byte(0x3F, OLED_CMD); //duty = 1/64�?00h~3Fh
    OLED_I2C_Write_Byte(0xC8, OLED_CMD); //com scan direction --- Com口扫描方向，C0h/C8h
    OLED_I2C_Write_Byte(0xD3, OLED_CMD); //set display offset --- 设置显示抵消
    OLED_I2C_Write_Byte(0x00, OLED_CMD); //00h~3Fh

    OLED_I2C_Write_Byte(0xD5, OLED_CMD); //set osc division --- 设置时钟分配和振荡频�?
    OLED_I2C_Write_Byte(0x80, OLED_CMD);

    OLED_I2C_Write_Byte(0xD9, OLED_CMD); //set pre-charge period --- 设置预充电周�?
    OLED_I2C_Write_Byte(0x22, OLED_CMD);

    OLED_I2C_Write_Byte(0xDA, OLED_CMD); //set com pin configuration --- 设置COM口引脚配�?
    OLED_I2C_Write_Byte(0x12, OLED_CMD);

    OLED_I2C_Write_Byte(0xDB, OLED_CMD); //set vcomh --- 设置COM电压等级
    OLED_I2C_Write_Byte(0x20, OLED_CMD); //0x00 —�? 0.65*Vcc
                                         //0x10 —�? 0.71*Vcc
                                         //0x20 —�? 0.77*Vcc
                                         //0x30 —�? 0.83*Vcc

    OLED_I2C_Write_Byte(0x8D, OLED_CMD); //set charge pump enable --- 设置电荷泵使�?
    OLED_I2C_Write_Byte(0x14, OLED_CMD);
    OLED_I2C_Write_Byte(0xAF, OLED_CMD); //display on --- 打开显示
}

/*line:0-7;column:0-128 
设置时line+1实际增加8
设置时column+1实际增加1
*/
void OLED_SetPos(unsigned char line, unsigned char column) //设置起始点坐�?
{
    OLED_I2C_Write_Byte(0xb0 + line, OLED_CMD);     /*设置页地址*/
    OLED_I2C_Write_Byte((column & 0x0F), OLED_CMD); /*设置列地址*/
    OLED_I2C_Write_Byte((column >> 4) | 0x10, OLED_CMD);
}

void OLED_Fill(unsigned char fill_Data) //全屏填充
{
    unsigned char m, n;
    for (m = 0; m < 8; m++)
    {
        OLED_I2C_Write_Byte(0xb0 + m, OLED_CMD); //page0-page1
        OLED_I2C_Write_Byte(0x00, OLED_CMD);     //low column start address
        OLED_I2C_Write_Byte(0x10, OLED_CMD);     //high column start address
        for (n = 0; n < 128; n++)
        {
            OLED_I2C_Write_Byte(fill_Data, OLED_DAT);
        }
    }
}

void OLED_CLS(void) //清屏
{
    OLED_Fill(0x00);
}

void OLED_ON(void)
{
    OLED_I2C_Write_Byte(0X8D, OLED_CMD); //设置电荷�?
    OLED_I2C_Write_Byte(0X14, OLED_CMD); //开启电荷泵
    OLED_I2C_Write_Byte(0XAF, OLED_CMD); //OLED唤醒
}

void OLED_OFF(void)
{
    OLED_I2C_Write_Byte(0X8D, OLED_CMD); //设置电荷�?
    OLED_I2C_Write_Byte(0X10, OLED_CMD); //关闭电荷�?
    OLED_I2C_Write_Byte(0XAE, OLED_CMD); //OLED休眠
}

void show_char_a_type(uint8_t line, uint8_t column, unsigned char *array)
{
    uint8_t i = 0;

    OLED_SetPos(line, column);
    for (i = 0; i < 8; i++)
    {
        OLED_I2C_Write_Byte(array[i], OLED_DAT);
    }
    OLED_SetPos(line + 1, column);
    for (i = 0; i < 8; i++)
    {
        OLED_I2C_Write_Byte(array[i + 8], OLED_DAT);
    }
}

void show_char_a1type(uint8_t line, uint8_t column, char character)
{
    uint8_t i = 0;

    for (i = 0; i < ASC_16_num; i++)
    {
        if (ASC_16[i].Index[0] == character)
            break;
    }

    if (i == ASC_16_num)
        return;

    show_char_a_type(line, column, ASC_16[i].Msk);
}

void show_string_atype(uint8_t line, uint8_t column, char *data, uint8_t len)
{
    uint8_t i = 0;

    for (i = 0; i < len; i++)
    {
        show_char_a1type(line, column, *data);
        column += 1 * 8;
        data += 1;
    }
}

void show_hz(uint8_t line, uint8_t column, unsigned char *array)
{
    uint8_t i = 0;

    OLED_SetPos(line, column);
    for (i = 0; i < 16; i++)
    {
        OLED_I2C_Write_Byte(array[i], OLED_DAT);
    }
    OLED_SetPos(line + 1, column);
    for (i = 0; i < 16; i++)
    {
        OLED_I2C_Write_Byte(array[i + 16], OLED_DAT);
    }
}
/*
*****************************************************************
功能描述：显示一个汉�?
函数属性：外部调用
说明事项：调用show_hz()函数

入口参数：lin:�?(0-7), column: �?(0-7)  array: 字模区数�?   black:是否反白显示标志(0:正常显示，非0：反白显�?)
出口参数：void

应用实例：show_hanzi(2, 0, "�?");         //显示一个汉�?"�?"  宽x�?=16x16
*****************************************************************
*/
void show_hanzi(uint8_t line, uint8_t column, char *data)
{
    unsigned int i;

    for (i = 0; i < GB_16_num; i++)
    {
        if (GB_16[i].Index[0] == data[0] && GB_16[i].Index[1] == data[1] && GB_16[i].Index[2] == data[2])
        {
            break;
        }
    }

    if (i == GB_16_num)
    {
        return;
    }
    show_hz(line, column, GB_16[i].Msk);
}

/*
*****************************************************************
功能描述：显示一串中文简体输�?
函数属性：外部调用
说明事项：查表显示输�?        汉字输出个数num: num < 8 - column

入口参数：lin:�?(0-7), column: �?(0-7)  array: 字模区数�?	black:是否反白显示标志(0:正常显示，非0：反白显�?)
出口参数：void

*****************************************************************
*/

void show_chs_string(uint8_t line, uint8_t column, char *data)
{
    while (*data != '\0')
    {
        show_hanzi(line, column, data);
        column += 1 * 16;
        data += 1 * 3; /*UTF-8,一个汉字GB码由3个字节组成*/
    }
}
/*显示图片BMP
line0:0-7;column0:0-127
line1:0-7;column0:1-127
*/
void show_drawBMP(unsigned char line0, unsigned char column0, unsigned char line1, unsigned char column1, unsigned char BMP[])
{
    unsigned int tmp = 0;
    unsigned char line = 0, column = 0;

    for (line = line0; line <= line1; line++)
    {
        OLED_SetPos(line, column0);
        for (column = column0; column <= column1; column++)
        {
            OLED_I2C_Write_Byte(BMP[tmp++], OLED_DAT);
        }
    }
}
u32 oled_pow(u8 m, u8 n)
{
    u32 result = 1;
    while (n--)
        result *= m;
    return result;
}
