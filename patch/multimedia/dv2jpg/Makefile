# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD: head/multimedia/dv2jpg/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	dv2jpg
PORTVERSION=	1.1
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Type-2 DV codec-encoded AVI streams to mjpeg-encoded AVI

LIB_DEPENDS=	dv:${PORTSDIR}/multimedia/libdv

USE_GNOME=	gdkpixbuf
MAKEFILE=	makefile

PLIST_FILES=	bin/avijoin \
		bin/dv2jpg

PORTDOCS=	README.avilib README.dv2jpg.html

OPTIONS_SINGLE=	VIDEO-FORMAT
OPTIONS_SINGLE_VIDEO-FORMAT=	NTSC PAL
OPTIONS_DEFAULT=	NTSC

VIDEO-FORMAT_DESC=	Use default video format
NTSC_DESC=	Default video format NTSC
PAL_DESC=	Default video format PAL

.include <bsd.port.options.mk>

post-extract:
	${INSTALL_DATA} ${FILESDIR}/makefile ${WRKSRC}
	${RM} -f ${WRKSRC}/avijoin ${WRKSRC}/dv2jpg ${WRKSRC}/*.o

post-patch:
	@${REINPLACE_CMD} -e 's|/opt/vidpb/lib/avilib.h|avilib.h|' \
		${WRKSRC}/avijoin.c

.if ${PORT_OPTIONS:MPAL}
	@${REINPLACE_CMD} -e 's|VIDEO=NTSC|# VIDEO=NTSC|' \
		-e 's|# VIDEO=PAL|VIDEO=PAL|' \
		${WRKSRC}/${MAKEFILE}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avijoin ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dv2jpg ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
