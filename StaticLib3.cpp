// StaticLib3.cpp : 定义静态库的函数。
#include "pch.h"
//#include "framework.h"

// TODO: 这是一个库函数示例
//#include "gmpxx.h"
//#include <stdio.h>
//#include <gmp.h>
//#include <gmpxx.h>
void factorial1(mpz_t n, mpz_t m) {
    mpz_t result;
    mpz_init(result);
    mpz_set_ui(result, 1);
    mpz_add_ui(n, n, 1);
    for (; mpz_cmp(n, m) != 0; mpz_add_ui(n, n, 1)) {
        mpz_mul(result, result, n);
    }
    mpz_mul(n, m, result);
    mpz_clear(result);
    mpz_clear(m);
}
void factorial2(mpz_t m, mpz_t n) {
    mpz_t z, t, k, j, g, num;
    mpz_init(num);
    mpz_set_si(num, 3);
    mpz_init(z);
    mpz_init(t);
    mpz_init(k);
    mpz_init(j);
    mpz_init(g);
    mpz_sub(z, n, m);
    mpz_fdiv_q(t, z, num);
    mpz_mod(z, z, num);
    mpz_add_ui(m, m, 2);
    mpz_mul(k, m, m);
    mpz_mul_ui(j, m, 27);
    mpz_mul_2exp(g, j, 1);
    mpz_add_ui(g, g, 162);
    mpz_mul_ui(num, k, 9);
    mpz_add_ui(num, num, 24);
    mpz_add(j, j, num);
    mpz_mul(k, k, m);
    mpz_sub(k, k, m);
    if (mpz_cmp_ui(z, 1) == 0) {
        mpz_set(m, n);
    }
    else {
        mpz_set_ui(m, 1);
        if (mpz_cmp_ui(z, 2) == 0) {
            mpz_sub_ui(m, n, 1);
            mpz_mul(m, m, n);
        }
    }
    mpz_mul_ui(t, t, 162);
    mpz_add(t, t, g);
    while (mpz_cmp(g, t) != 0) {
        mpz_mul(m, m, k);
        mpz_add(k, k, j);
        mpz_add(j, j, g);
        mpz_add_ui(g, g, 162);
    }
    mpz_clear(num);
    mpz_clear(z);
    mpz_clear(t);
    mpz_clear(k);
    mpz_clear(j);
    mpz_clear(g);
    mpz_clear(n);
}
void difference(mpz_t array[], long long int rows) {
    long long int f, g, v, b, s, d, k, z, a, w = rows - 1;
    mpz_t** arr;
    arr = (mpz_t**)malloc(rows * sizeof(mpz_t*));
    z = rows;
    for (long long int i = 0; i != rows; ++i) {
        arr[i] = (mpz_t*)malloc((z) * sizeof(mpz_t));
        for (long long int j = 0; j != z; ++j) {
            mpz_init(arr[i][j]);
            mpz_set_si(arr[i][j], 0);
        }
        --z;
    }
    mpz_set_ui(arr[0][1], 1);
    mpz_set_ui(arr[0][2], 1);
    d = 2;
    for (long long int i = 3; i != rows; ++i) {
        s = d;
        mpz_set(arr[0][i], arr[0][d]);
        for (long long int j = d; j != 1; --j) {
            --s;
            mpz_mul_ui(arr[0][j], arr[0][j], d);
            mpz_add(arr[0][j], arr[0][j], arr[0][s]);
        }
        mpz_mul_ui(arr[0][1], arr[0][1], d);
        ++d;
    }
    z = rows;
    mpz_t** arr2 = (mpz_t**)malloc(rows * sizeof(mpz_t*));
    for (long long int i = 0; i != rows; ++i) {
        arr2[i] = (mpz_t*)malloc(z * sizeof(mpz_t));
        for (long long int j = 0; j != z; ++j) {
            mpz_init(arr2[i][j]);
            mpz_set_si(arr2[i][j], 0);
        }
        --z;
    }
    mpz_init(array[0]);
    mpz_set_si(array[0], w);
    for (long long int i = 1; i != rows; ++i) {
        mpz_init(array[i]);
        mpz_mul(array[i], array[i - 1], array[0]);
    }
    g = w;
    a = w;
    mpz_t o;
    mpz_init(o);
    for (long long int i = 0; i != w; i++) {
        b = a; g += -1; a = g; s = a; d = 1; k = (s >> 1) + (s & 1); z = 0;
        mpz_set_si(o, 1); mpz_set(arr2[i][0], array[s]);
        while (s != k) {
            mpz_mul_ui(o, o, b);
            mpz_tdiv_q_ui(o, o, d);
            b = s;
            mpz_mul(arr2[i][s], o, array[z]);
            s += -1;
            mpz_mul(arr2[i][d], o, array[s]);
            z = d;
            d += 1;
        }
        if (d == s) {
            mpz_mul_ui(o, o, b);
            mpz_tdiv_q_ui(o, o, d);
            mpz_mul(arr2[i][s], o, array[z]);
        }
    }
    mpz_t bs;
    mpz_init(bs);
    f = 1; k = 0; g = w;
    while (g != 0) {
        a = g;
        z = w - a;
        while (z != w) {
            mpz_set(o, arr[k][a]);
            --a;
            s = a;
            while (s != -1) {
                mpz_mul(bs, o, arr2[z][s]);
                mpz_add(arr[f][s], arr[f][s], bs);
                --s;
            }
            ++z;
        }
        k = f; ++f; --g;
    }
    mpz_clear(bs);
    z = rows;
    for (long long int i = 0; i != rows; ++i) {
        for (long long int j = 0; j != z; ++j) {
            mpz_clear(arr2[i][j]);
        }
        free(arr2[i]);
        --z;
    }
    free(arr2);
    for (long long int i = 0; i != rows; ++i) {
        mpz_set_ui(array[i], 0);
    }
    b = 0;
    z = rows;
    while (b != rows) {
        d = z;
        while (d != 0) {
            --d;
            mpz_add(array[b], array[b], arr[b][d]);
            mpz_clear(arr[b][d]);
        }
        free(arr[b]);
        --z;
        ++b;
    }
    free(arr);
}
void factorial3(mpz_t y, mpz_t u) {
    long long int rows, w, n, a, y1, u1, n1;
    mpz_t r, r1, s;
    mpz_init(r);
    mpz_init(r1);
    mpz_init(s);
    mpz_sub(r, u, y);
    if (mpz_cmp_ui(r, 8192) < 0) {
        factorial2(y, u);
        return;
    }
    y1 = mpz_get_ui(y); u1 = mpz_get_ui(u);
    mpz_sqrt(r, r); mpz_sqrt(r, r);
    a = mpz_get_ui(r);
    rows = a << 1;
    w = rows - 1;
    n = u1 / w; mpz_set_ui(r1, n * w); n1 = y1 / w; ++n1;
    mpz_set_ui(r, n1 * w);
    mpz_t* array;
    array = (mpz_t*)malloc(rows * sizeof(mpz_t));
    difference(array, rows);
    if (y1 == 0 || y1 == 1) {
        n1 = 0;
        mpz_set(r, y);
    }
    else {
        for (long long int i = 0; i != n1; ++i) {
            for (long long int j = 0; j != w; ++j) {
                mpz_add(array[j], array[j], array[j + 1]);
            }
        }
    }
    n = n - n1;
    mpz_set_ui(s, 1);
    for (long long int i = 0; i != n; ++i) {
        mpz_mul(s, s, array[0]);
        for (long long int j = 0; j != w; ++j) {
            mpz_add(array[j], array[j], array[j + 1]);
        }
    }
    for (long long int i = 0; i != rows; i++) {
        mpz_clear(array[i]);
    }
    free(array);
    factorial3(y, r);
    factorial3(r1, u);
    mpz_mul(y, y, s);
    mpz_mul(y, y, r1);
    mpz_clear(r1);
    mpz_clear(s);
}
void factorial4(mpz_t y, mpz_t u) {
    long long int a, b, s, d, k, z, rows, w, n, v;
    mpz_t r;
    mpz_init(r);
    mpz_sub(r, u, y);
    if (mpz_cmp_ui(r, 8192) < 0) {
        factorial2(y, u);
        return;
    }
    z = mpz_get_ui(r);
    mpz_sqrt(r, r);
    mpz_sqrt(r, r);
    a = mpz_get_ui(r);
    rows = a << 1;
    w = rows - 1;
    n = z / rows;
    a = n * w;
    mpz_sub_ui(r, u, a);
    mpz_t** arr;
    arr = (mpz_t**)malloc(rows * sizeof(mpz_t*));
    z = rows;
    for (long long int i = 0; i != rows; ++i) {
        arr[i] = (mpz_t*)malloc((z) * sizeof(mpz_t));
        for (long long int j = 0; j != (z); ++j) {
            mpz_init(arr[i][j]);
            mpz_set_si(arr[i][j], 0);
        }
        --z;
    }
    mpz_set_si(arr[0][1], -1);
    mpz_set_si(arr[0][3], 1);
    long long int g = rows + 1;
    long long int f;
    mpz_t sb, bs;
    mpz_init(sb);
    mpz_set_si(sb, -4);
    mpz_init(bs);
    mpz_set_si(bs, -5);
    for (long long int i = 5; i != g; i += 2) {
        f = i;
        for (long long int j = i; j != 1;) {
            mpz_mul(arr[0][j], arr[0][j], sb);
            f += -2;
            mpz_add(arr[0][j], arr[0][j], arr[0][f]);
            j = f;
        }
        mpz_mul(arr[0][1], arr[0][1], sb);
        mpz_add(sb, sb, bs);
        mpz_sub_ui(bs, bs, 2);
    }
    mpz_clear(sb);
    mpz_t* array;
    array = (mpz_t*)malloc(rows * sizeof(mpz_t));
    mpz_init(array[0]);
    mpz_set_si(array[0], w);
    for (long long int i = 1; i != rows; ++i) {
        mpz_init(array[i]);
        mpz_mul(array[i], array[i - 1], array[0]);
    }
    z = rows;
    mpz_t** arr2 = (mpz_t**)malloc(rows * sizeof(mpz_t*));
    for (long long int i = 0; i != rows; ++i) {
        arr2[i] = (mpz_t*)malloc(z * sizeof(mpz_t));
        for (long long int j = 0; j != z; ++j) {
            mpz_init(arr2[i][j]);
            mpz_set_si(arr2[i][j], 0);
        }
        --z;
    }
    g = w;
    a = w;
    mpz_t o;
    mpz_init(o);
    for (long long int i = 0; i != w; i++) {
        b = a; g += -1; a = g; s = a; d = 1; k = (s >> 1) + (s & 1); z = 0;
        mpz_set_si(o, 1); mpz_set(arr2[i][0], array[s]);
        while (s != k) {
            mpz_mul_ui(o, o, b);
            mpz_tdiv_q_ui(o, o, d);
            b = s;
            mpz_mul(arr2[i][s], o, array[z]);
            s += -1;
            mpz_mul(arr2[i][d], o, array[s]);
            z = d;
            d += 1;
        }
        if (d == s) {
            mpz_mul_ui(o, o, b);
            mpz_tdiv_q_ui(o, o, d);
            mpz_mul(arr2[i][s], o, array[z]);
        }
    }
    f = 1; k = 0; g = w;
    while (g != 0) {
        a = g;
        z = w - a;
        while (z != w) {
            mpz_set(o, arr[k][a]);
            --a;
            s = a;
            while (s != -1) {
                mpz_mul(bs, o, arr2[z][s]);
                mpz_add(arr[f][s], arr[f][s], bs);
                --s;
            }
            ++z;
        }
        k = f; ++f; --g;
    }
    mpz_clear(bs);
    z = rows;
    for (long long int i = 0; i != rows; ++i) {
        for (long long int j = 0; j != z; ++j) {
            mpz_clear(arr2[i][j]);
        }
        free(arr2[i]);
        --z;
    }
    free(arr2);
    mpz_set_ui(o, 1);
    v = (rows >> 1) + mpz_get_ui(r);
    g = w;
    for (long long int i = 1; i != rows; ++i) {
        mpz_mul_ui(o, o, v);
        --g;
        for (long long int j = g; j != -1; --j) {
            mpz_mul(arr[j][i], arr[j][i], o);
        }
    }
    for (long long int i = 0; i != rows; ++i) {
        mpz_set_ui(array[i], 0);
    }
    b = 0;
    z = rows;
    while (b != rows) {
        d = z;
        while (d != 0) {
            --d;
            mpz_add(array[b], array[b], arr[b][d]);
            mpz_clear(arr[b][d]);
        }
        free(arr[b]);
        --z;
        ++b;
    }
    free(arr);
    factorial4(y, r);
    for (long long int i = 0; i != n; ++i) {
        mpz_mul(y, y, array[0]);
        for (long long int j = 0; j != w; ++j) {
            mpz_add(array[j], array[j], array[j + 1]);
        }
    }
    mpz_clear(u);
    for (long long int i = 0; i != rows; i++) {
        mpz_clear(array[i]);
    }
    free(array);
}

