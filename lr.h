#ifndef LR_H
#define LR_H

#include <vector>
#include <unordered_map>
#include "grammar.h" // for Prodcution definition

using namespace std;

enum type
{
    SHIFT,
    REDUCE,
    GOTO,
    ACC,
    ERROR
};

struct Action
{
    type act;
    int content;
};
using state_id = int;
using terminal_table = unordered_map<char, Action>;
using non_terminal_table = unordered_map<char, Action>;

using ActionTable = unordered_map<state_id, terminal_table>;
using GotoTable = unordered_map<state_id, non_terminal_table>;

using ProductionTable = unordered_map<int, Production>;
using ProductionPriority = unordered_map<int, char>;


ActionTable actionTable = {
    {0, {{'i', {SHIFT, 5}}, {'+', {ERROR, -1}}, {'*', {ERROR, -1}}, {'(', {SHIFT, 4}}, {')', {ERROR, -1}}, {'#', {ERROR, -1}}}},
    {1, {{'i', {ERROR, -1}}, {'+', {SHIFT, 6}}, {'*', {ERROR, -1}}, {'(', {ERROR, -1}}, {')', {ERROR, -1}}, {'#', {ACC, -1}}}},
    {2, {{'i', {ERROR, -1}}, {'+', {REDUCE, 2}}, {'*', {SHIFT, 7}}, {'(', {ERROR, -1}}, {')', {REDUCE, 2}}, {'#', {REDUCE, 2}}}},
    {3, {{'i', {ERROR, -1}}, {'+', {REDUCE, 4}}, {'*', {REDUCE, 4}}, {'(', {ERROR, -1}}, {')', {REDUCE, 4}}, {'#', {REDUCE, 4}}}},
    {4, {{'i', {SHIFT, 5}}, {'+', {ERROR, -1}}, {'*', {ERROR, -1}}, {'(', {SHIFT, 4}}, {')', {ERROR, -1}}, {'#', {ERROR, -1}}}},
    {5, {{'i', {ERROR, -1}}, {'+', {REDUCE, 6}}, {'*', {REDUCE, 6}}, {'(', {ERROR, -1}}, {')', {REDUCE, 6}}, {'#', {REDUCE, 6}}}},
    {6, {{'i', {SHIFT, 5}}, {'+', {ERROR, -1}}, {'*', {ERROR, -1}}, {'(', {SHIFT, 4}}, {')', {ERROR, -1}}, {'#', {ERROR, -1}}}},
    {7, {{'i', {SHIFT, 5}}, {'+', {ERROR, -1}}, {'*', {ERROR, -1}}, {'(', {SHIFT, 4}}, {')', {ERROR, -1}}, {'#', {ERROR, -1}}}},
    {8, {{'i', {ERROR, -1}}, {'+', {SHIFT, 6}}, {'*', {ERROR, -1}}, {'(', {ERROR, -1}}, {')', {SHIFT, 11}}, {'#', {ERROR, -1}}}},
    {9, {{'i', {ERROR, -1}}, {'+', {REDUCE, 1}}, {'*', {SHIFT, 7}}, {'(', {ERROR, -1}}, {')', {REDUCE, 1}}, {'#', {REDUCE, 1}}}},
    {10, {{'i', {ERROR, -1}}, {'+', {REDUCE, 3}}, {'*', {REDUCE, 3}}, {'(', {ERROR, -1}}, {')', {REDUCE, 3}}, {'#', {REDUCE, 3}}}},
    {11, {{'i', {ERROR, -1}}, {'+', {REDUCE, 5}}, {'*', {REDUCE, 5}}, {'(', {ERROR, -1}}, {')', {REDUCE, 5}}, {'#', {REDUCE, 5}}}},
};

GotoTable gotoTable = {
    {0, {{'E', {GOTO, 1}}, {'T', {GOTO, 2}}, {'F', {GOTO, 3}}}},
    {1, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {ERROR, -1}}}},
    {2, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {ERROR, -1}}}},
    {3, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {ERROR, -1}}}},
    {4, {{'E', {GOTO, 8}}, {'T', {GOTO, 2}}, {'F', {GOTO, 3}}}},
    {5, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {ERROR, -1}}}},
    {6, {{'E', {ERROR, -1}}, {'T', {GOTO, 9}}, {'F', {GOTO, 3}}}},
    {7, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {GOTO, 10}}}},
    {8, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {ERROR, -1}}}},
    {9, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {ERROR, -1}}}},
    {10, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {ERROR, -1}}}},
    {11, {{'E', {ERROR, -1}}, {'T', {ERROR, -1}}, {'F', {ERROR, -1}}}},
};

ProductionPriority productionPriority = {{0, 'L'}, {1, 'E'}, {2, 'T'}, {3, 'F'}};
ProductionTable productionTable;

#endif
