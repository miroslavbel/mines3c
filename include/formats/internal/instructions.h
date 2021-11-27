#ifndef MINES3C_FORMATS_INTERNAL_INSTRUCTIONS__H
#define MINES3C_FORMATS_INTERNAL_INSTRUCTIONS__H

#include <inttypes.h> // uint8_t

#include <formats/internal/literals.h>

#pragma region InstructionIdsEnum
/*!
 * \brief Id инструкций из клиента.
 *
 * \note Здесь не определены id для инструкций <code>LAST, RESTART</code>.
 *
 * \warning Id со значениями <code>34, 41-42, 55-56, 61-73, 75, 78-118</code>
 * отсутствуют.
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

    InstructionId_CELL_WA = 29,
    InstructionId_CELL_SD = 30,
    InstructionId_CELL_W = 31,
    InstructionId_CELL_DW = 32,
    InstructionId_CELL_A = 33,
    InstructionId_CELL_D = 35,
    InstructionId_CELL_AS = 36,
    InstructionId_CELL_S = 37,

    InstructionId_BOOLMODE_OR = 38,
    InstructionId_BOOLMODE_AND = 39,

    InstructionId_LABEL = 40,

    InstructionId_CC_NOTEMPTY = 43,
    InstructionId_CC_EMPTY = 44,
    InstructionId_CC_GRAVITY = 45,
    InstructionId_CC_CRYSTALL = 46,
    InstructionId_CC_ALIVE = 47,
    InstructionId_CC_BOLDER = 48,
    InstructionId_CC_SAND = 49,
    InstructionId_CC_ROCK = 50,
    InstructionId_CC_DEAD = 51,
    InstructionId_CCC_REDROCK = 52,
    InstructionId_CCC_BLACKROCK = 53,
    InstructionId_CC_ACID = 54,
    InstructionId_CCC_QUADRO = 57,
    InstructionId_CCC_ROAD = 58,
    InstructionId_CCC_REDBLOCK = 59,
    InstructionId_CCC_YELLOWBLOCK = 60,
    InstructionId_CCC_BOX = 74,
    InstructionId_CCC_OPOR = 76,
    InstructionId_CCC_GREENBLOCK = 77,
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
    Instruction_RETURN1, Instruction_CELL_WA, Instruction_CELL_SD,
    Instruction_CELL_W, Instruction_CELL_DW, Instruction_CELL_A,
    Instruction_CELL_D, Instruction_CELL_AS, Instruction_CELL_S,
    Instruction_BOOLMODE_OR, Instruction_BOOLMODE_AND, Instruction_CC_NOTEMPTY,
    Instruction_CC_EMPTY, Instruction_CC_GRAVITY, Instruction_CC_CRYSTALL,
    Instruction_CC_ALIVE, Instruction_CC_BOLDER, Instruction_CC_SAND,
    Instruction_CC_ROCK, Instruction_CC_DEAD, Instruction_CCC_REDROCK,
    Instruction_CCC_BLACKROCK, Instruction_CC_ACID, Instruction_CCC_QUADRO,
    Instruction_CCC_ROAD, Instruction_CCC_REDBLOCK, Instruction_CCC_YELLOWBLOCK,
    Instruction_CCC_BOX, Instruction_CCC_OPOR, Instruction_CCC_GREENBLOCK;

/*! \struct tagLiteralInstruction
 * \brief Инструкция, содержащая в себе литерал идентификатора метки.
 */
typedef struct tagLiteralInstruction {
    LabelIdentificatorLiteral label;
} Instruction_GOTO, Instruction_GOSUB, Instruction_GOSUB1, Instruction_LABEL;
#pragma endregion InstructionTypeDeclarations

/*!
 * \brief Объединение типов инструкций.
 *
 * По факту является объедением двух структур: #tagSimpleInstruction и
 * #tagLiteralInstruction.
 *
 * \warning Не содержит в себе типы для инструкций <code>LAST, RESTART</code>,
 * т. к. их типы не известны.
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

    Instruction_CELL_WA CELL_WA;
    Instruction_CELL_SD CELL_SD;
    Instruction_CELL_W CELL_W;
    Instruction_CELL_DW CELL_DW;
    Instruction_CELL_A CELL_A;
    Instruction_CELL_D CELL_D;
    Instruction_CELL_AS CELL_AS;
    Instruction_CELL_S CELL_S;

    Instruction_BOOLMODE_OR BOOLMODE_OR;
    Instruction_BOOLMODE_AND BOOLMODE_AND;

    Instruction_LABEL LABEL;

    Instruction_CC_NOTEMPTY CC_NOTEMPTY;
    Instruction_CC_EMPTY CC_EMPTY;
    Instruction_CC_GRAVITY CC_GRAVITY;
    Instruction_CC_CRYSTALL CC_CRYSTALL;
    Instruction_CC_ALIVE CC_ALIVE;
    Instruction_CC_BOLDER CC_BOLDER;
    Instruction_CC_SAND CC_SAND;
    Instruction_CC_ROCK CC_ROCK;
    Instruction_CC_DEAD CC_DEAD;
    Instruction_CCC_REDROCK CCC_REDROCK;
    Instruction_CCC_BLACKROCK CCC_BLACKROCK;
    Instruction_CC_ACID CC_ACID;
    Instruction_CCC_QUADRO CCC_QUADRO;
    Instruction_CCC_ROAD CCC_ROAD;
    Instruction_CCC_REDBLOCK CCC_REDBLOCK;
    Instruction_CCC_YELLOWBLOCK CCC_YELLOWBLOCK;
    Instruction_CCC_BOX CCC_BOX;
    Instruction_CCC_OPOR CCC_OPOR;
    Instruction_CCC_GREENBLOCK CCC_GREENBLOCK;
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
