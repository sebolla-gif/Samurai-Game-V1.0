## :hammer_and_wrench:Advertencia: el videojuego está en la etapa inicial de desarrollo:hammer_and_wrench:

# Samurai-Game-V1.0

Bienvenido a Samurai Game V1.0, un juego 2D desarrollado con Allegro en C++. En este juego, los jugadores controlan a un samurái que debe superar varios desafíos y enemigos.

## Características

- **Gráficos 2D:** Utiliza la biblioteca Allegro para gráficos y animaciones.
- **Controles:** Controla al samurái usando entradas de teclado.

> [!NOTE]
> El contenido de la carpeta `bin` en este momento solo contiene un ejecutable `.exe` del juego para que puedas probarlo.

## Recomendaciones para el desarrollo

- **Sistema Operativo:** Windows
- **Bibliotecas:** Allegro 4.2
- **Entorno de Desarrollo:** Code::Blocks 17.12 (recomendado)

## Estado del Desarrollo

Actualmente en desarrollo:

- **Mecánicas de Combate:** Explorando un tipo de combate tipo vs.
- **Diseño de Niveles:** Diseñando un modo de supervivencia con niveles cronometrados.
- **Gráficos y Sonido:** Añadiendo más animaciones y sonido al juego.
- **Enemigos y Desafíos:** Generando más obstáculos y enemigos para el modo de un jugador.

## Notas:

Todas las imágenes .bmp utilizadas en el programa están ubicadas en la carpeta `resources`. Con la configuración actual, puedes modificar fácilmente la matriz para usar cualquier imagen .bmp que prefieras para tus personajes en el programa. La matriz sigue este formato:

Los dos primeros valores son la disposición por columnas de las imágenes de izquierda a derecha, y el tercer valor es la fila en la que se encuentra la imagen. Los otros tres valores son los mismos, pero para las imágenes orientadas a la izquierda.

{0, 5, 10, 16, 21, 0}, *idle*

{0, 8, 11, 13, 21, 1}, *walk*

{0, 7, 12, 14, 21, 2}, *run*

{0, 3, 13, 18, 21, 3}, *attack1*

{0, 4, 14, 17, 21, 4}, *attack2*

{0, 3, 15, 18, 21, 5}, *attack3*

{0, 1, 16, 20, 21, 6}, *protection*

{0, 8, 17, 13, 21, 7}, *jump*

{0, 2, 18, 19, 21, 8}, *hurt*

{0, 5, 19, 16, 21, 9} *dead*

> [!IMPORTANT]
> Ten en cuenta que la imagen del samurái está recortada en cajas de 128x128 píxeles.

## Comentarios y contribuciones

Se agradecen los comentarios y contribuciones:
- Comparte ideas e informa sobre problemas para ayudar a mejorar el juego.
- Haz un fork del repositorio, crea ramas y envía pull requests.

## Hoja de ruta

Casi toda la atención del programa está centrada en mejorar la lógica y en separar mejor las partes del personaje de la lógica del juego. También falta terminar la parte del menú y se deben generar los diferentes modos de juego. El proyecto aún tiene un largo camino por recorrer, pero habrá más novedades en los próximos meses.

## Licencia

Este proyecto está licenciado bajo la [Licencia MIT](LICENSE).

 
 ## :hammer_and_wrench:Warning: the video game is in the early development stage:hammer_and_wrench:


# Samurai-Game-V1.0

Welcome to Samurai Game V1.0, a 2D game developed with Allegro in C++. In this game, players control a samurai who must overcome various challenges and enemies.

## Features

- **2D Graphics:** Uses the Allegro library for graphics and animations.
- **Controls:** Control the samurai using keyboard inputs.
  
> [!NOTE]
> The contents of the `bin` folder at the moment only contain an `.exe` executable of the game so you can test it.

## Recommendations for development

- **Operating System:** Windows
- **Libraries:** Allegro 4.2
- **Development Environment:** Code::Blocks 17.12 (recommended)

## Development Status

Currently in development:

- **Combat Mechanics:** Exploring a type of vs. combat.
- **Level Design:** Designing a survival mode with timed levels.
- **Graphics and Sound:** Add more animations and sound to the game.
- **Enemies and Challenges:** Generate more masks to add obstacles and enemies for single player mode.

## Notes:

All .bmp images used in the program are located in the `resources` folder. With the current setup, you can easily modify the matrix to use any .bmp image you prefer for your characters in the program. The matrix follows this format:

The first two values ​​are the column-wise arrangement of images from left to right, and the third value is the row in which the image is located. The other three values ​​are the same but for left-facing images.

{0, 5, 10, 16, 21, 0}, *idle*

{0, 8, 11, 13, 21, 1}, *walk*

{0, 7, 12, 14, 21, 2}, *run*

{0, 3, 13, 18, 21, 3}, *attack1*

{0, 4, 14, 17, 21, 4}, *attack2*

{0, 3, 15, 18, 21, 5}, *attack3*

{0, 1, 16, 20, 21, 6}, *protection*

{0, 8, 17, 13, 21, 7}, *jump*

{0, 2, 18, 19, 21, 8}, *hurt*

{0, 5, 19, 16, 21, 9} *dead*

> [!IMPORTANT]
> Please note that the samurai image is cropped into 128x128 pixel boxes.

## Feedback and contributions

Feedback and contributions are appreciated:
- Share ideas and report issues to help improve the game.
- Fork the repository, create branches, and submit pull requests.

## Roadmap

Almost all the program's attention is focused on improving the logic and better separating the character's parts from the game logic. The menu part also needs to be finished and the different game modes need to be generated. The project still has a long way to go, but there will be more news in the next few months.

## License

This project is licensed under the [MIT License](LICENSE).
