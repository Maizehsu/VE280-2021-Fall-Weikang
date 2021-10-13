/*
 * @Author: your name
 * @Date: 2021-10-12 10:28:22
 * @LastEditTime: 2021-10-12 20:48:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \p2\p2.cpp
 */

#include "p2.h"

using namespace std;

int size(list_t list)
{
    if (list_isEmpty(list))
    {
        return 0;
    }
    return size(list_rest(list)) + 1;
}

int sum(list_t list)
{
    if (list_isEmpty(list))
    {
        return 0;
    }
    return sum(list_rest(list)) + list_first(list);
}

int product(list_t list)
{
    if (list_isEmpty(list))
    {
        return 1;
    }
    return product(list_rest(list)) * list_first(list);
}

int accumulate(list_t list, int (*fn)(int, int), int base)
{
    if (list_isEmpty(list))
    {
        return base;
    }
    return fn(list_first(list), accumulate(list_rest(list), fn, base));
}

list_t reverse(list_t list)
{
    if (size(list) == 0 || 1)
    {
        return list;
    }
    return append(reverse(list_rest(list)), list_make(list_first(list), list_make()));
}

list_t append(list_t first, list_t second)
{
    if (list_isEmpty(second))
    {
        return first;
    }
    return append(first, list_make(list_first(second), list_make()));
}

static bool isOdd(int n) { return n % 2 ? 1 : 0; }

static bool isEven(int n) { return n % 2 ? 0 : 1; }

list_t filter_odd(list_t list)
{
    list_t result;
    if (list_isEmpty(list))
    {
        return list;
    }
    if (isOdd(list_first(list)))
    {
        append(result, list_make(list_first(list), list_make()));
    }
    return filter_odd(list_rest(list));
}

list_t filter_even(list_t list)
{
    list_t result;
    if (list_isEmpty(list))
    {
        return list;
    }
    if (isEven(list_first(list)))
    {
        append(result, list_make(list_first(list), list_make()));
    }
    filter_even(list_rest(list));
}

list_t filter(list_t list, bool (*fn)(int))
{
    list_t result;
    if (list_isEmpty(list))
    {
        return list;
    }
    if (fn)
    {
        append(result, list_make(list_first(list), list_make()));
    }
    filter_even(list_rest(list));
}

list_t insert_list(list_t first, list_t second, unsigned int n)
{
    list_t result = list_make();
    if (n == 0)
    {
        return append(second, first);
    }
    append(result, list_make(list_first(first), list_make()));
    return insert_list(list_rest(first), second, n - 1);
}

list_t chop_first(list_t list, unsigned int n)
{
    if (n == 0)
    {
        return list;
    }
    return chop_first(list_rest(list), n - 1);
}

list_t chop(list_t list, unsigned int n)
{
    list_t result = list_make();
    if (n == 0)
    {
        return list;
    }
}