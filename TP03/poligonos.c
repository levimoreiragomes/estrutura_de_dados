#include <stdio.h>

typedef struct {
    float X;
    float Y;
} Ponto;

int main() {
    FILE *arquivo;
    int numVertices;

    arquivo = fopen("vertices.txt", "r");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);


    if (numVertices < 3) {
        printf("O poligono deve ter pelo menos 3 vertices.\n");
        fclose(arquivo);
        return 1;
    }

    Ponto vertices[numVertices];
    float area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(arquivo);

    for (int i = 0; i < numVertices - 1; i++) {
        area += (vertices[i].X * vertices[i + 1].Y - vertices[i + 1].X * vertices[i].Y);
    }

    area += (vertices[numVertices - 1].X * vertices[0].Y - vertices[0].X * vertices[numVertices - 1].Y);

    area = 0.5 * area;

    if (area < 0) {
        area = -area;
    }

    printf("A area do poligono e %.2f\n", area);

    return 0;
}
