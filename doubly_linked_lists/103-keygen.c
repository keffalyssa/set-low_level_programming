k0 — f1(len): (strlen(username) ^ 0x3b) & 0x3f
k1 — f2(username): (sum of chars ^ 0x4f) & 0x3f
k2 — f3(username): (product of chars ^ 0x55) & 0x3f
k3 — f4(username): seeds srand(max_char ^ 0xe), returns rand() & 0x3f
k4 — f5(username): (sum of char² ^ 0xef) & 0x3f
k5 — f6(username[0]): calls rand() username[0] times, (last ^ 0xe5) & 0x3f
