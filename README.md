 ## :hammer_and_wrench:Warning: the video game is in the early development stage:hammer_and_wrench:


# Samurai-Game-V1.0

Welcome to Samurai Game V1.0, a 2D game developed with Allegro in C++. In this game, players control a samurai who must overcome various challenges and enemies.

## Features

- **2D Graphics:** Uses the Allegro library for graphics and animations.
- **Controls:** Control the samurai using keyboard inputs.

## System Requirements

- **Operating System:** Windows, macOS, or Linux
- **Libraries:** Allegro 4
- **Development Environment:** Code::Blocks 17.12 (recommended)

## Development Status

Currently in development:

- **Combat Mechanics:** Exploring a type of vs. combat.
- **Level Design:** Designing a survival mode with timed levels.
- **Graphics and Sound:** Add more animations and sound to the game.
- **Enemies and Challenges:** Generate more masks to add obstacles and enemies for single player mode.

## Notes:

All .bmp images used in the program are in the `resources` folder. In the way the program is set up, you can simply change the matrix to use any .bmp image you want for the program. The matrix used has this format:

The first three values ​​in each row are the right orientation, from where the images start to where they end and what row number they are in within the image. the other three values ​​are the same but for the reverse orientation

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

Almost all the program's attention is focused on improving the logic and better separating the character's parts from the game logic. The menu part is also missing and the different game modes need to be generated. The project still has a long way to go, but there will be more news in the next few months.

## License

This project is licensed under the [MIT License](LICENSE).
