MOD = 10**9 + 7
n, m, p, r = map(int, input().split())
result = 0

def print_all_paths_with_area(x, y, current_area = 0):
    global result
    # Caso base: raggiunto l'angolo in alto a destra
    if x == n or y == m:
        #print(str(current_area))
        if current_area % p == r:
            result = ((result + 1) % MOD)
        return

    # Muoviti verso destra se possibile
    if x < n:
        print_all_paths_with_area(x + 1, y, current_area)

    # Muoviti verso l'alto se possibile
    if y < m:
        print_all_paths_with_area(x, y + 1, current_area + n - x)

def solv():
    print_all_paths_with_area(0, 0)

solv()
print(result)

