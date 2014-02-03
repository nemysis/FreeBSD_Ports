# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vacuum-magic
DISTVERSION=	0.14r491
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/
DISTNAME=	vacuum-${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Fast-paced action game

LICENSE=	GPLv2

# According to vacuum.pl
BUILD_DEPENDS=	p5-SDL>=0:${PORTSDIR}/devel/p5-SDL \
		p5-OpenGL>=0:${PORTSDIR}/graphics/p5-OpenGL \
		p5-Carp>=0:${PORTSDIR}/devel/p5-Carp

WRKSRC=		${WRKDIR}/vacuum

USES=		shebangfix perl5
SHEBANG_FILES=	bin/fontmaker.pl bin/umtrans.pl bin/vacuum.pl bin/preparefont.pl
USE_SDL=	mixer image sdl sound net
NO_BUILD=	yes

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} pkg-message

DESKTOP_ENTRIES="Vacuum Magic" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" ""

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|SDL::App|SDLx::App|; \
		s|SDL::Timer|SDLx::Controller::Timer|; \
		s|SDL::Sound|SDLx::Sound|; \
		s|SDL::Font|SDL::TTF::Font|; \
		s|SDL::OpenGL|OpenGL|' \
		${WRKSRC}/bin/vacuum.pl
	@${REINPLACE_CMD} -e 's|SDL::OpenGL|OpenGL|' \
		${WRKSRC}/bin/GlFont.pm ${WRKSRC}/bin/Texture.pm \
		${WRKSRC}/bin/game.pl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "bin data" ${STAGEDIR}${DATADIR})

# Fix Permission that user can write in bin
	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} -R 774 bin)

	${LN} -sf ${DATADIR}/data/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/data/vacuum.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6/${PORTNAME}.6

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
