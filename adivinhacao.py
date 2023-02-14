print()
print("*********************************")
print("Bem vindo ao jogo de adivinhação!")
print("*********************************")

numero_secreto = 81
#total_de_tentativas = 100
chute = 0

print()
while(chute != numero_secreto):
    chute_str = input("Digite um número entre 0 e 100: ")
    #não compara string com número e não converte automaticamente, então tem que converter
    chute = int(chute_str)
    certo = chute == numero_secreto
    maior = chute > numero_secreto
    menor = chute < numero_secreto

    print()

    if(certo):
        print("Parabéns! Você acertou!")
    else:
        if(maior):
            print("Você errou, tente chutar um número menor.")
        elif(menor):
            print("Você errou, tente chutar um número maior.")

print("Fim do jogo.")
print()
