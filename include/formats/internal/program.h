#ifndef MINES3C_FORMATS_INTERNAL_PROGRAM__H
#define MINES3C_FORMATS_INTERNAL_PROGRAM__H

#include <formats/internal/instructions.h>

/*!
 * \brief Количество страниц в программаторе.
 */
#define PAGES_PER_PROGRAM 16
/*!
 * \brief Количество строк на странице в программаторе.
 */
#define ROWS_PER_PAGE 12
/*!
 * \brief Количество инструкций в строке в программаторе.
 */
#define INSTRUCTIONS_PER_ROW 16

/*!
 * \brief Программа во внутреннем представлении.
 *
 * Представляет из себя фиксированного размера массив инструкций. Таким образом
 * любая программа имеет один и тот же размер.
 *
 * \note Для инициализации достаточно заполнить память нулями, что установит все
 * инструкции в #Instruction_EMPTY. Для удаления достаточно удалить стандартным
 * аллокатором, так как не содержит ссылочных типов.
 */
typedef Instruction
    NativeProgram[PAGES_PER_PROGRAM * ROWS_PER_PAGE * INSTRUCTIONS_PER_ROW];

#endif /* MINES3C_FORMATS_INTERNAL_PROGRAM__H */
