#ifndef ESTABLECERCONSOLA_HPP_INCLUDED
#define ESTABLECERCONSOLA_HPP_INCLUDED

enum EstadoCursor {
    APAGADO,    /**< Cursor no visible */
    ENCENDIDO   /**< Cursor visible */
};

/** Modos de cursor visualmente simulados (sin efecto real en macOS) */
enum ModoCursor {
    MINI = 1,
    NORMAL = 40,
    SOLIDO = 80
};

void CambiarCursor(EstadoCursor estado, ModoCursor modo = NORMAL);
void MoverCursor(short x, short y);

#endif // ESTABLECERCONSOLA_HPP_INCLUDED
