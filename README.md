![Descripción](https://img.shields.io/badge/Descripción-blue?style=for-the-badge)

**get_next_line** es una función en C que lee un descriptor de archivo línea a línea, devolviendo cada llamada la siguiente línea completa (incluyendo el `\n`, si existe) hasta el final del fichero.  
Este proyecto refuerza conceptos de:
- Manejo de buffers y punteros.
- Lectura con `read()` de forma controlada.
- Gestión de memoria dinámica sin fugas.

![Estructura](https://img.shields.io/badge/Estructura-orange?style=for-the-badge)

```text
04.GNL-main/
├── includes/           
│   └── get_next_line.h     # Prototipos y constantes (BUFFER_SIZE)
├── srcs/                
│   ├── get_next_line.c     # Función principal
│   ├── get_next_line_utils.c # Helpers (ft_strlen, ft_strjoin, etc.)
│   └── ...
├── tests/                # (Opcional) Bancos de prueba personalizados
├── Makefile              # Reglas de compilación
└── libgnl.a              # Biblioteca estática generada
```

![Compilación](https://img.shields.io/badge/Compilación-blue?style=for-the-badge)

- make

- make all — Compila get_next_line.c y get_next_line_utils.c, genera libgnl.a.

- make clean — Elimina los objetos intermedios (*.o).

- make fclean— Además de clean, elimina libgnl.a.

- make re — Ejecuta fclean y luego all.

![Uso](https://img.shields.io/badge/Uso-yellow?style=for-the-badge)

    1. Incluye la cabecera en tu programa:
    
        #include "get_next_line.h"
    
    2. Enlaza con la biblioteca al compilar:
    
        gcc -L. -lgnl tu_programa.c -o tu_programa

    3. Invoca la función en tu código:
    
        #include <fcntl.h>
        #include <stdio.h>
        #include <stdlib.h>
        #include "get_next_line.h"
    
        int main(void)
        {
            int   fd = open("archivo.txt", O_RDONLY);
            char *line;
    
            if (fd < 0)
                return (1);
            while ((line = get_next_line(fd)))
            {
                printf("%s", line);
                free(line);
            }
            close(fd);
            return (0);
        }



![Autor](https://img.shields.io/badge/Autor-red?style=for-the-badge)

- Roberto del Olmo Lima
- [![GitHub](https://img.shields.io/badge/GitHub-Profile-informational?style=for-the-badge&logo=github&logoColor=white&color=181717)](https://github.com/legrol)
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/roberto-del-olmo-731746245)
