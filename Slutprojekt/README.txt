------------------------------------------------------------------
SPELET

* Spelet är ett Space Invaders-inspirerat spel som går ut på att man ska skjuta sönder kometer och rymdskepp som kommer in på skärmen. Varje meteor ger 10 poäng, fiendeskeppen ger 5 poäng.

* Var hundrade poäng ändras nivån (det finns 3 nivåer) och det börjar "spawna" fiender mer frekvent.

* Spelarskeppet tål 3 fiendeskott, och sprängs direkt vid kollision med både fiender såväl som kometer.

* Meteorer tål 3 skott och studsar vid kollision med fiender och spelarskepp.

* Fiender tål 1 skott och sprängs vid kollision med spelarskepp och meteorer.

------------------------------------------------------------------
KONTROLLER

* W - Accelerera framåt.
* A - Svänga vänster.
* S - Backa.
* D - Svänga höger.

* SPACE - skjuta laserskott.

* ESC - Gå till startmenyn.
------------------------------------------------------------------
FILER OCH MAPPAR

* Working Directory för projektet måste vara satt till katalogen som den här README-filen ligger i.

* Underkatalogen "api" som ligger i den här katalogen bör vara tillagd så att den absluta sökvägen inte behöver anges i #include-direktiv i header-filerna och .cpp-filerna som ligger i "game"-katalogen. T.ex. kan man, om man använder Visual Studio lägga till api-katalogen som ett include directory. Om man använder XCode behöver man bara sätta working directory till projektets mapp för att filerna ska hittas.

* Alla resursfiler, det vill säga bildfiler och fonter måste ligga i en katalog "resources" i katalogen som den här README-filen ligger. Resources måste i sin tur innehålla en mapp som heter Backgrounds, som i sin tur ska innehålla bakgrundsbilder. I resources måste det även finnas en mapp som heter Spritesheet där spritesheets för explosioner och för alla andra sprites ska ligga. I resources måste även font-filen "kenvector-future.ttf" ligga, men inte i någon undermapp, utan direkt i resources.

* SDL-bibliotekens headerfiler måste finnas tillagda så att den utvecklingsmiljö man använder kan hitta dem genom följande angivelser i #include-direktiv:
    - SDL2/SDL.h (SDL2-biblioteket)
    - SDL2_image/SDL_image.h (SDL2 Image-bibliotek)
    - SDL2_ttf/SDL_ttf.h (SDL2 TTF-bibliotek)

* Sökvägar för bildfiler och font:
/resources/ -- här ska font-filen ligga.
/resources/Backgrounds/ -- här ska bakgrunderna ligga.
/resources/Spritesheet/ -- här ska explosion.png och sheet.png ligga.
------------------------------------------------------------------
