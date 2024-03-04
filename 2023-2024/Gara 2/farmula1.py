points = [0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1]
input_file = open("input.txt", mode = "r")

t = int(input_file.readline().strip())

for _ in range(t):
    # Leggiamo la riga bianca facendo un readline inutile
    input_file.readline()

    n = int(int(input_file.readline()))
    
    daniel_score = 0
    max_score = 0
    # Lista con le posizioni di Daniel
    results = list(map(int, input_file.readline().split()))
    
    # L'idea è calcolare quanti punti ha fatto Daniel e
    # quanti punti ha fatto il primo in classifica
    # Se Daniel è arrivato primo allora prendiamo il secondo classificato
    for i in range(n):
        position = int(results[i])

        # Se Daniel non è arrivato primo
        if position != 1:
            max_score += 25
        else:
            max_score += 18
 
        if position <= 10:
            daniel_score += points[position]
    
    if daniel_score >= max_score:
        print("Champion")
    else:
        print("Practice harder")
