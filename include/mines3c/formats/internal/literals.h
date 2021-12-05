#ifndef MINES3C_FORMATS_INTERNAL_LITERALS__H
#define MINES3C_FORMATS_INTERNAL_LITERALS__H

#include <inttypes.h> // uint8_t

// ## C-шный тип

/*!
 * \brief Заглушка.
 *
 * Служит для выравнивания.
 *
 * \warning Значение может быть любым.
 */
typedef uint8_t _LiteralStub[3];

// ## Типы по содержанию

/*!
 * \brief Литерал, состоящий только из цифр.
 *
 * Должен соответствовать регулярному выражению <code>\d{1,3}</code>. Должен
 * быть валидной строкой в ascii кодировке.
 *
 * \warning Не является нуль-терминированной строкой.
 */
typedef _LiteralStub _DigitsLiteral;

/*!
 * \brief Литерал, состоящий только из цифр и букв.
 *
 * Должен соответствовать регулярному выражению <code>[\d\w]{1,3}</code>. Должен
 * быть валидной строкой в ascii кодировке.
 *
 * \warning Не является нуль-терминированной строкой.
 */
typedef _LiteralStub _DigitsAndLettersLiteral;

// ## Семантические типы

/*!
 * \brief Литерал значений переменной.
 *
 * Должен соответствовать регулярному выражению <code>\d{1,3}</code>. Должен
 * быть валидной строкой в ascii кодировке.
 *
 * \warning Не является нуль-терминированной строкой.
 */
typedef _DigitsLiteral VariableValueLiteral;

/*!
 * \brief Литерал идентификатора переменной.
 *
 * Должен соответствовать регулярному выражению <code>[\d\w]{1,3}</code>. Должен
 * быть валидной строкой в ascii кодировке.
 *
 * \warning Не является нуль-терминированной строкой.
 */
typedef _DigitsAndLettersLiteral VariableIdentificatorLiteral;

/*!
 * \brief Литерал идентификатора метки.
 *
 * Должен соответствовать регулярному выражению <code>[\d\w]{1,3}</code>. Должен
 * быть валидной строкой в ascii кодировке.
 *
 * \warning Не является нуль-терминированной строкой.
 */
typedef _DigitsAndLettersLiteral LabelIdentificatorLiteral;

/*!
 * \brief Литерал строки.
 *
 * Должен соответствовать регулярному выражению <code>[\d\w]{1,3}</code>. Должен
 * быть валидной строкой в ascii кодировке.
 *
 * \warning Не является нуль-терминированной строкой.
 */
typedef _DigitsAndLettersLiteral StringLiteral;

#endif /* MINES3C_FORMATS_INTERNAL_LITERALS__H */
