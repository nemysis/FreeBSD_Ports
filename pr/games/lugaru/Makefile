# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lugaru
PORTVERSION=	269
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-rev${DISTVERSION}-src

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	3D arcade with unique fighting system and anthropomorphic characters

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg

USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_GL=		glu
USE_OPENAL=	soft
USE_SDL=	sdl
USE_XORG=	ice x11 xext

PORTDOCS=	README

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Lugaru" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/lugaru|${PREFIX}/share/${PORTNAME}|' ${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${LN} -sf ${DATADIR}/Data/Textures/Lugaru.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
