#ifndef MINES3C_FORMATS_INTERNAL_INSTRUCTIONS__H
#define MINES3C_FORMATS_INTERNAL_INSTRUCTIONS__H

#include <inttypes.h> // uint8_t

#include <formats/internal/literals.h>

#pragma region InstructionIdsEnum
/*!
 * \brief Id инструкций из клиента.
 *
 * \note Здесь определены #InstructionId_LAST, #InstructionId_RESTART, но типы
 * для них не приводятся, т. к. не известны.
 */
enum InstructionIds {
    InstructionId_EMPTY = 0,
    InstructionId_BACK = 1,

    InstructionId_START = 2,
    InstructionId_STOP = 3,

    InstructionId_MOVE_W = 4,
    InstructionId_MOVE_A = 5,
    InstructionId_MOVE_S = 6,
    InstructionId_MOVE_D = 7,

    InstructionId_DIGG = 8,

    InstructionId_LOOK_W = 9,
    InstructionId_LOOK_A = 10,
    InstructionId_LOOK_S = 11,
    InstructionId_LOOK_D = 12,

    InstructionId_LAST = 13,

    InstructionId_LOOK_F = 14,

    InstructionId_ROTATE_CCW = 15,
    InstructionId_ROTATE_CW = 16,

    InstructionId_ACTION_BUILD = 17,
    InstructionId_ACTION_GEO = 18,
    InstructionId_ACTION_ROAD = 19,
    InstructionId_ACTION_HEAL = 20,
    InstructionId_ACTION_QUADRO = 21,
    InstructionId_ACTION_RANDOM = 22,
    InstructionId_ACTION_BIBIKA = 23,

    InstructionId_GOTO = 24,
    InstructionId_GOSUB = 25,
    InstructionId_GOSUB1 = 26,
    InstructionId_RETURN = 27,
    InstructionId_RETURN1 = 28,
};
#pragma endregion InstructionIdsEnum

#pragma region InstructionTypeDeclarations
/*! \struct tagSimpleInstruction
 * \brief Простая инструкция, не содержащая в себе никакой информации.
 *
 * Используется для определения инструкции, которая не содержит в себе
 * литералов. Таких инструкций большинство.
 */
typedef struct tagSimpleInstruction {
} Instruction_EMPTY, Instruction_BACK, Instruction_START, Instruction_STOP,
    Instruction_MOVE_W, Instruction_MOVE_A, Instruction_MOVE_S,
    Instruction_MOVE_D, Instruction_DIGG, Instruction_LOOK_W,
    Instruction_LOOK_A, Instruction_LOOK_S, Instruction_LOOK_D,
    Instruction_LOOK_F, Instruction_ROTATE_CCW, Instruction_ROTATE_CW,
    Instruction_ACTION_BUILD, Instruction_ACTION_GEO, Instruction_ACTION_ROAD,
    Instruction_ACTION_HEAL, Instruction_ACTION_QUADRO,
    Instruction_ACTION_RANDOM, Instruction_ACTION_BIBIKA, Instruction_RETURN,
    Instruction_RETURN1;

/*! \struct tagLiteralInstruction
 * \brief Инструкция, содержащая в себе литерал идентификатора метки.
 */
typedef struct tagLiteralInstruction {
    LabelIdentificatorLiteral label;
} Instruction_GOTO, Instruction_GOSUB, Instruction_GOSUB1;
#pragma endregion InstructionTypeDeclarations

/*!
 * \brief Объединение типов инструкций.
 *
 * По факту является объедением двух структур: #tagSimpleInstruction и
 * #tagLiteralInstruction.
 *
 * \warning Не содержит в себе типы для инструкций \a LAST и \a RESTART, т.
 * к. их типы не известны.
 */
typedef union tagInstructionTypesUnion {
    Instruction_EMPTY EMPTY;
    Instruction_BACK BACK;

    Instruction_START START;
    Instruction_STOP STOP;

    Instruction_MOVE_W MOVE_W;
    Instruction_MOVE_A MOVE_A;
    Instruction_MOVE_S MOVE_S;
    Instruction_MOVE_D MOVE_D;

    Instruction_DIGG DIGG;

    Instruction_LOOK_W LOOK_W;
    Instruction_LOOK_A LOOK_A;
    Instruction_LOOK_S LOOK_S;
    Instruction_LOOK_D LOOK_D;
    Instruction_LOOK_F LOOK_F;

    Instruction_ROTATE_CCW ROTATE_CCW;
    Instruction_ROTATE_CW ROTATE_CW;

    Instruction_ACTION_BUILD ACTION_BUILD;
    Instruction_ACTION_GEO ACTION_GEO;
    Instruction_ACTION_ROAD ACTION_ROAD;
    Instruction_ACTION_HEAL ACTION_HEAL;
    Instruction_ACTION_QUADRO ACTION_QUADRO;
    Instruction_ACTION_RANDOM ACTION_RANDOM;
    Instruction_ACTION_BIBIKA ACTION_BIBIKA;

    Instruction_GOTO GOTO;
    Instruction_GOSUB GOSUB;
    Instruction_GOSUB1 GOSUB1;
    Instruction_RETURN RETURN;
    Instruction_RETURN1 RETURN1;
} InstructionTypesUnion;

/*!
 * \brief Представляет инструкцию.
 */
typedef struct tagInstruction {
    /*!
     * \brief Id инструкции.
     *
     * Валидные id инструкций перечислены в #InstructionIds.
     */
    uint8_t id;
    /*!
     * \brief Сама инструкция.
     *
     * \see #InstructionsUnion.
     */
    InstructionTypesUnion instruction;
} Instruction;

#endif /* MINES3C_FORMATS_INTERNAL_INSTRUCTIONS__H */
