# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD: head/games/ppracer/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	ppracer
DISTVERSION=	0.5alpha
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}.berlios/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	3D downhill racing game... kind of like TuxRacer Improved

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_SDL=	mixer sdl
USE_GL=		gl
USES=		desktop-file-utils
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)

PORTDOCS=	AUTHORS ChangeLog ChangeLog-pre0.3.9 ChangeLog-tuxracer

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|libpng12|libpng15|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|RacingMode::||' ${WRKSRC}/src/racingmode.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
