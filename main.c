#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Yıldız işlemleri çok fazla kullanılacağından fonksiyonel hale getirelim
 * 2 için * *, 3 için * * * metni döndürür
 */
char* create_indents(int level) {
    char* text = malloc(0);
    for (int i = 0; i < level; i++) {
        strcat(text, " ");
    }
    return text;
}

/**
 * Girinti işlemleri çok fazla kullanılacağından fonksiyonel hale getirelim
 * 2 için "  ", 3 için "   " metni döndürür
 */
char* create_stars(int level) {
    char* text = malloc(0);
    for (int i = 0; i < level; i++) {
        if (i == 0) {
            strcat(text, "*");
        }
        else {
            strcat(text, " *");
        }
    }
    return text;
}

/**
 * Üst üçgen için son kısma ekleme yapılacak
 */
char* append_up_triangle(char* up_triangle, int level, int n){
    strcat(up_triangle, "\n");
    strcat(up_triangle, create_indents(n - (level + 1)));
    strcat(up_triangle,  "/ /");
    strcat(up_triangle,  create_stars(level + 1));
    strcat(up_triangle,  "\\ \\");
    return up_triangle;
}

/**
 * Alt üçgen için baş kısma ekleme yapılacak
 */
char* append_down_triangle(char* down_triangle, int level, int n){
    char* text = malloc(0);
    strcat(text, create_indents(n - (level + 1)));
    strcat(text, "\\ \\");
    strcat(text, create_stars(level + 1));
    strcat(text, "/ /\n");
    strcat(text, down_triangle);
    return text;
}

int main() {

    // Üçgen çiziminde benzer alanları belirlememiz gerekmektedir (n = 2)
    //    _ _
    //   / | \
    //  / /*\ \
    // / /* *\ \
    // \ \* */ /
    //  \ \*/ /
    //   \ | /
    //    - -
    int n;
    printf("Boyutu girin: ");
    scanf("%d", &n);

    // Yukarıdaki şekilde 2 tane üçgen vardır ve teki ters çevrilmiştir
    // Bu üçgenleri up_triagle ve down_triangle olarak adlandıralım
    //    Üst         Alt
    //    _ _      \ \* */ /
    //   / | \      \ \*/ /
    //  / /*\ \      \ | /
    // / /* *\ \      - -
    char up_triangle[] = "";
    char down_triangle[] = "";

    // Girinti değerlerini n değerine göre hesaplamalıyız, n = 2 için girintileri ve yıldızları inceleyelim
    //    Üst                  Alt
    //    _ _    3 girinti  \ \* */ /  0 girinti
    //   / | \   2 girinti   \ \*/ /   1 girinti
    //  / /*\ \  1 girinti    \ | /    2 girinti
    // / /* *\ \ 0 girinti     - -     3 girinti

    // Dikkatli bakıldığın üst ve alt üçgenlerde sabit bir alan var
    // Bu alanları üçgen çizimine başlamadan, önce up ve down triangle içine eklemeliyiz
    //    _ _  \ | /
    //   / | \  - -
    strcat(up_triangle, create_indents(n + 1));
    strcat(up_triangle, "_ _\n");
    strcat(up_triangle, create_indents(n));
    strcat(up_triangle, "/ | \\");

    strcat(down_triangle, create_indents(n));
    strcat(down_triangle, "\\ | /\n");
    strcat(down_triangle, create_indents(n + 1));
    strcat(down_triangle, "- -");

    // Sabit kısımları yaptığımıza göre artık değişken kısımlara odaklanmalıyız
    //     Üst    level + 1   n - (level + 1)      Alt      
    //  / /*\ \   1 yıldız       1 girinti      \ \* */ /  2 yıldız  0 girinti,  level = 0
    // / /* *\ \  2 yıldız       0 girinti       \ \*/ /   1 yıldız  1 girinti,  level = 1

    // Girintiler aynı olduğundan, yeni çizimi üst üçgen için alt satıra, alt üçgen için üst satıra eklemeliyiz
    // / /* *\ \ 2 yıldız  0 girinti her iki üçgen için de aynıdır (append_up_triangle, append_down_triangle fonskiyonlarına bakın)

    // Artık tüm n değerleri için programı oluşturabiliriz
    //    _ _
    //   / | \
    //  / /*\ \
    // / /* *\ \
    // \ \* */ /
    //  \ \*/ /
    //   \ | /
    //    - -

    for (int i = 0; i < n; i++)
    {
        strcat(up_triangle, append_up_triangle(up_triangle, i, n));
        strcat(down_triangle, append_down_triangle(down_triangle, i, n));
    }
    strcat(up_triangle, "\n");
    strcat(up_triangle, down_triangle);
    printf("%s", up_triangle);

    return 0;
}