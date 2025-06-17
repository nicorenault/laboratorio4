#include "../include/CargaDatos.h"
#include <cstddef>
#include "IControladorSistema.h"
#include "Factory.h"
CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    IControladorSistema* cs =
        Factory::getInstance()->getControladorSistema();
    IControladorFechaActual* cf = Factory::getInstance()->getControladorFechaActual();

    cs->altaCliente(
        "luisito23",
        "qweasd12",
        "Luis",
        "luisito23@gmail.com",
        "Pérez",
        "46859342"
    );
    cs->finalizarAltaUsuario();

    cs->altaCliente(
        "anarojo88",
        "claveAna1",
        "Ana",
        "anarojo88@hotmail.com",
        "Rojo",
        "31287465"
    );

    cs->finalizarAltaUsuario();


    cs->altaPropietario("marcelom", "banco123",   "Marcelo", "marcelo.m@gmail.com",   "123456789012", "099876543");
    cs->altaCasa       ("Av. Rivera", 1011, 120,    1995,      true,           TipoTecho::Plano);
    cs->altaApartamento("Av. Brasil", 2031, 75,     1980,      5,              true,           3500.0f);
    cs->finalizarAltaUsuario();

    cs->altaPropietario("robertarce", "pass456",  "Roberto", "roberto.a@yahoo.com",    "987654321001","091234567");
    cs->altaCasa       ("Camino Maldonado", 1540, 95, 1988,      false,          TipoTecho::Plano);
    cs->finalizarAltaUsuario();

    cs->altaPropietario("soledadf",   "sole789",   "Soledad", "soledad.f@gmail.com",    "654321987654","092345678");
    cs->altaApartamento("Colonia",    1542, 60,     1978,      12,             true,           2800.0f);
    cs->finalizarAltaUsuario();

    cs->altaPropietario("martagal",   "martA01",   "Marta",   "marta.galvez@outlook.com","321098765432","098765432");
    cs->altaCasa       ("Juan Paullier", 801, 110,   2000,      true,           TipoTecho::Liviano);
    cs->finalizarAltaUsuario();

    cs->altaPropietario("jorge88",    "jorgepass88","Jorge",  "jorge.rivera@uy.com",     "890123456789","097654321");
    cs->altaApartamento("Bulevar Artigas", 871, 68, 2002,      3,              false,          2200.0f);
    cs->altaApartamento("Sarmiento",  1476, 80,     2008,      6,              true,           3100.0f);
    cs->altaCasa       ("Cno. Carrasco", 1576,140,  2007,      true,           TipoTecho::Plano);
    cs->finalizarAltaUsuario();

    cs->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
    cs->representarPropietario("marcelom");
    cs->representarPropietario("jorge88");
    cs->finalizarAltaUsuario();

    cs->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy", "Av. Italia 4567", "https://idealhome.uy", "099123456");
    cs->representarPropietario("marcelom");
    cs->representarPropietario("martagal");
    cs->representarPropietario("jorge88");
    cs->finalizarAltaUsuario();

    cs->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
    cs->representarPropietario("robertarce");
    cs->representarPropietario("soledadf");
    cs->representarPropietario("jorge88");
    cs->finalizarAltaUsuario();

    cf->setNewFechaActual(12, 12, 2015);
    cs->altaAdministraPropiedad("casasur123", 2);

    cf->setNewFechaActual(25, 9, 2023);
    cs->altaAdministraPropiedad("idealhome", 1);

    cf->setNewFechaActual(20, 7, 2022);
    cs->altaAdministraPropiedad("vivaurbana", 3);

    cf->setNewFechaActual(1, 1, 2022);
    cs->altaAdministraPropiedad("vivaurbana", 4);

    cf->setNewFechaActual(3, 7, 2010);
    cs->altaAdministraPropiedad("idealhome", 5);

    cf->setNewFechaActual(4, 11, 2019);
    cs->altaAdministraPropiedad("casasur123", 6);

    cf->setNewFechaActual(19, 5, 2020);
    cs->altaAdministraPropiedad("vivaurbana", 6);

    cf->setNewFechaActual(19, 7, 2024);
    cs->altaAdministraPropiedad("idealhome", 6);

    cf->setNewFechaActual(18, 9, 2023);
    cs->altaAdministraPropiedad("idealhome", 7);

    cf->setNewFechaActual(19, 5, 2022);
    cs->altaAdministraPropiedad("vivaurbana", 8);

    cs->suscribirUsuario("luisito23",  "casasur123");
    cs->suscribirUsuario("luisito23",  "idealhome");
    cs->suscribirUsuario("anarojo88",  "casasur123");
    cs->suscribirUsuario("anarojo88",  "idealhome");
    cs->suscribirUsuario("anarojo88",  "vivaurbana");
    cs->suscribirUsuario("marcelom",   "idealhome");
    cs->suscribirUsuario("robertarce", "idealhome");
    cs->suscribirUsuario("soledadf",   "vivaurbana");
    cs->suscribirUsuario("martagal",   "vivaurbana");
    cs->suscribirUsuario("jorge88",    "casasur123");
    cs->suscribirUsuario("jorge88",    "idealhome");
    cs->suscribirUsuario("jorge88",    "vivaurbana");

    cf->setNewFechaActual(12, 10, 2011);
    cs->altaPublicacion("idealhome",  5, TipoPublicacion::Venta,
        "Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000.0f);

    cf->setNewFechaActual(15,  1, 2016);
    cs->altaPublicacion("casasur123", 2, TipoPublicacion::Alquiler,
        "Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000.0f);

    cf->setNewFechaActual( 5,  3, 2019);
    cs->altaPublicacion("casasur123", 2, TipoPublicacion::Alquiler,
        "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500.0f);

    cf->setNewFechaActual( 3,  4, 2019);
    cs->altaPublicacion("idealhome",  5, TipoPublicacion::Alquiler,
        "Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500.0f);

    cf->setNewFechaActual(12, 12, 2019);
    cs->altaPublicacion("casasur123", 6, TipoPublicacion::Venta,
        "Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 375000.0f);

    cf->setNewFechaActual(12,  6, 2020);
    cs->altaPublicacion("casasur123", 2, TipoPublicacion::Venta,
        "Excelente apartamento en Av. Brasil con 75 m ideal para reforma.", 390000.0f);

    cf->setNewFechaActual(20,  7, 2020);
    cs->altaPublicacion("vivaurbana", 6, TipoPublicacion::Alquiler,
        "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000.0f);

    cf->setNewFechaActual( 4,  3, 2022);
    cs->altaPublicacion("vivaurbana", 4, TipoPublicacion::Alquiler,
        "Apartamento con ascensor en Colonia 1542 piso 12 excelente vista.", 26000.0f);

    cf->setNewFechaActual(12,  9, 2022);
    cs->altaPublicacion("vivaurbana", 3, TipoPublicacion::Alquiler,
        "Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000.0f);

    cf->setNewFechaActual( 1, 10, 2023);
    cs->altaPublicacion("idealhome",  1, TipoPublicacion::Venta,
        "Casa en Av. Rivera de 120 m con techo plano ideal para familia.", 520000.0f);

    cf->setNewFechaActual(18, 10, 2023);
    cs->altaPublicacion("idealhome",  7, TipoPublicacion::Alquiler,
        "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000.0f);

    cf->setNewFechaActual(19, 10, 2023);
    cs->altaPublicacion("idealhome",  7, TipoPublicacion::Venta,
        "Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000.0f);

    cf->setNewFechaActual(20, 11, 2023);
    cs->altaPublicacion("idealhome",  7, TipoPublicacion::Alquiler,
        "Apartamento con gran vista a la rambla.", 31000.0f);

    cf->setNewFechaActual( 8,  3, 2024);
    cs->altaPublicacion("vivaurbana", 3, TipoPublicacion::Venta,
        "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000.0f);

    cf->setNewFechaActual( 5,  5, 2024);
    cs->altaPublicacion("idealhome",  7, TipoPublicacion::Alquiler,
        "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000.0f);

    cf->setNewFechaActual( 1,  8, 2024);
    cs->altaPublicacion("idealhome",  6, TipoPublicacion::Venta,
        "A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000.0f);




}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}