/**
 * @file reader.h
 * @author LionZXY
 * @project Seminar
 * @date 08.09.17
 * @email nikita@kulikof.ru
 **/
#ifndef SEMINAR_READER_H
#define SEMINAR_READER_H

struct ArrayList {
    int bufferSize;
    int realSize;
    int *array;
} typedef ArrayList;

int getIntArray(ArrayList *outList);

int getInt(int *out);

#endif //SEMINAR_READER_H
