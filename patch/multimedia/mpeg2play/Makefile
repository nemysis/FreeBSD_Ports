# Created by: Philippe Charnier <charnier@lirmm.fr>
# $FreeBSD: head/multimedia/mpeg2play/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	mpeg2play
PORTVERSION=	1.1b
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.funet.fi/pub/graphics/packages/mpeg/mpeg2play/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to play mpeg-2 movies on X displays

USE_IMAKE=	yes
USE_XORG=	x11 xext xp xt
USE_MOTIF=	yes
ALL_TARGET=	mpeg2play

PLIST_FILES=	bin/${PORTNAME} \
		lib/X11/app-defaults/Mpeg2play

PORTDOCS=	README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lXm -lXt -lX11 -lm|$${MOTIFLIB} -lXt -lX11 -lm|' \
		${WRKSRC}/Imakefile
	@${REINPLACE_CMD} -e 's|tell(base.infile);|lseek(base.infile, 0L, SEEK_CUR);|' \
		${WRKSRC}/mpeg2play.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg2play ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mpeg2play ${PREFIX}/lib/X11/app-defaults

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
