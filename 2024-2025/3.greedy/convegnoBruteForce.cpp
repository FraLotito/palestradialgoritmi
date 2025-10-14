int coppie(int N, int C[]) {
    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                int current = j;
                while (current != -1 && current != i) {
                    current = C[current];
                }
                if (current == i) {
                    result++;
                }
            }
        }
    }

    return result;
}
