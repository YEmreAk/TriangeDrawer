# Üçgen çiziminde benzer alanları belirlememiz gerekmektedir (n = 2)
#    _ _
#   / | \
#  / /*\ \
# / /* *\ \
# \ \* */ /
#  \ \*/ /
#   \ | /
#    - -
n = int(input("Boyutu girin: "))

# Yukarıdaki şekilde 2 tane üçgen vardır ve teki ters çevrilmiştir
# Bu üçgenleri up_triagle ve down_triangle olarak adlandıralım
#    Üst         Alt
#    _ _      \ \* */ /
#   / | \      \ \*/ /
#  / /*\ \      \ | /
# / /* *\ \      - -
up_triangle = ""
down_triangle = ""

# Girinti değerlerini n değerine göre hesaplamalıyız, n = 2 için girintileri ve yıldızları inceleyelim
#    Üst                  Alt
#    _ _    3 girinti  \ \* */ /  0 girinti
#   / | \   2 girinti   \ \*/ /   1 girinti
#  / /*\ \  1 girinti    \ | /    2 girinti
# / /* *\ \ 0 girinti     - -     3 girinti

# Yıldız ve girinti işlemleri çok fazla kullanılacağından fonksiyonel hale getirelim
def create_indents(level):
    return " " * level

def create_stars(level):
    return " ".join("*" * level)

# Dikkatli bakıldığın üst ve alt üçgenlerde sabit bir alan var
# Bu alanları üçgen çizimine başlamadan, önce up ve down triangle içine eklemeliyiz
#    _ _  \ | /
#   / | \  - -
up_triangle  = create_indents(n + 1) + "_ _" + "\n" + create_indents(n) + "/ | \\"
down_triangle = create_indents(n) + "\\ | /" + "\n" + create_indents(n + 1) + "- -"

# Sabit kısımları yaptığımıza göre artık değişken kısımlara odaklanmalıyız
#     Üst    level + 1   n - (level + 1)      Alt      
#  / /*\ \   1 yıldız       1 girinti      \ \* */ /  2 yıldız  0 girinti,  level = 0
# / /* *\ \  2 yıldız       0 girinti       \ \*/ /   1 yıldız  1 girinti,  level = 1

# Girintiler aynı olduğundan, yeni çizimi üst üçgen için alt satıra, alt üçgen için üst satıra eklemeliyiz
# / /* *\ \ 2 yıldız  0 girinti her iki üçgen için de aynıdır

# Üst üçgen için son kısma ekleme yapılacak
def append_up_triangle(up_triangle, level, n):
    return up_triangle + "\n" + create_indents(n - (level + 1)) + "/ /" + create_stars(level + 1) + "\\ \\"

# Alt üçgen için baş kısma ekleme yapılacak
def append_down_triangle(down_triangle, level, n):
    return create_indents(n - (level + 1)) + "\\ \\" + create_stars(level + 1) + "/ /" + "\n" + down_triangle


# Artık tüm n değerleri için programı oluşturabiliriz
#    _ _
#   / | \
#  / /*\ \
# / /* *\ \
# \ \* */ /
#  \ \*/ /
#   \ | /
#    - -
for i in range(n):
    up_triangle = append_up_triangle(up_triangle, i, n)
    down_triangle = append_down_triangle(down_triangle, i, n)
triangle = up_triangle + "\n" + down_triangle
print(triangle) 