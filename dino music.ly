
%Recreation of Music from the Original 1986 Version of The Dinosaur Game by Ray Arias
%Coded for GNU LilyPond 2.18.2.1 by Ray Arias, 14 - 16 April 2018

\version "2.18.2.1"

\header{
    title = "Music from Original 1986 Version of The Dinosaur Game" }

\paper {
    markup-system-spacing #'basic-distance = #16
    system-system-spacing #'basic-distance = #16 }

\score {
    \relative c' {
        \time 4/4 \repeat volta 8 {
            << \stemDown <c g'>1 _"Organ Sound" \\
                \stemUp { f'4\rest ^"Guitar Sound" c16 c f f g b d c b a b8 } >> |
            << \stemDown <c,, f>2 \\ \stemUp { c'16 f f a c b8. } >>
                << \stemDown <c,, f>2 \\ \stemUp { c'16 f f a c b8. } >> |
            << \stemDown <d,, g>2 \\ \stemUp { c'16 f g a g f g8 } >>
                << \stemDown <c,, f>2 \\ \stemUp { d'16 e f g f e f8 } >> |
            << \stemDown <d, f>1 \\ \stemUp { d'16 e f g8. f e d4 } >> |
            << \stemDown <e, g>1 \\ \stemUp { f'16 a b a g f a8 e16 g a g f d e8 } >> |
            << \stemDown <c, e>1 \\ \stemUp { c'16 d e f8. e d b16 c8. } >> | }
        }

    \layout {
        indent = 0 \cm
        short-indent = 0 \cm
        \context {
            \Score \remove "Bar_number_engraver" }
        }

    \midi {
        \tempo 4 = 75 }
}
