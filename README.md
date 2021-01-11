# Репозиторий для лабораторных работ по дисциплине "Прикладная информатика"
---
## Лабораторная работа №1
Построить график функции на отрезке от [x0, x1]
На стандартный поток ввода подаются 4 числа:
- Количество “столбиков” (целое число), то есть отрезок надо разбить на такое количество равным маленьких отрезочков и на каждом считать функцию постоянной.
- “Высота” графика в клеточках -- расстояние от верхней точки графика до нижней(целое число). Иными словами, надо будет посчитать функцию на каждом маленьком отрезке и “растянуть” его так, чтобы расстояние от самого маленького значения функции до самого большого, на этом отрезке, было высотой ровно в это количество клеточек.
- x0 (число с плавающей точкой)
- x1 (число с плавающей точкой)

## Лабораторная работа №2
а) Надо создать класс safe_long_long_t, который ведет себя ТОЧНО так же как обычный лонг лонг. 
- Конструкторы
- operator=
- Помните про модификаторы доступа
- Арифметические операторы
- Операторы сравнения
- operator<< для вывода и operator>> для ввода

б) Создать класс safe_c_array_t
- При создании принимает размер и выделяет массив через new
- При разрушении удаляет выделенный массив
- Можно получить доступ к значениям через operator[]
- Умеет копироваться

## Лабораторная работа №3
Надо реализовать свой [ДВУсвязный список](https://ru.wikipedia.org/wiki/Связный_список#Линейный_связный_список) интов, на основе [декларации](https://pastebin.com/mX2qn41u).
Есть выделенный внутри класса подкласс node_t в нем надо хранить информацию для каждой вершины списка.
O(x) -- [O-нотация](https://habr.com/ru/post/444594/)
В main надо написать какой-то набор тестов, что ваш класс работает правильно.

## Лабораторная работа №4
Необходимо сделать проект, для игры в шашки. Реализовать стратегию для человека и две РАЗЛИЧНЫЕ стратегии компьютера. Провести между компьютерными стратегиями турнир и выявить какая из них лучше. Делать надо по аналогии с [проектом с лекции](https://github.com/burakov28/teach-project).
Доп требования: использовать std::{unordered_}set, std::{unordered_}map, std::vector, std::string.
