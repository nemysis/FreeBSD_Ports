# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD: head/multimedia/mkxvcd/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	mkxvcd
PORTVERSION=	2.0.2
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	SF/kvcd4nix/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes high quality X/K/S/VCD movies from many formats

LICENSE=	GPLv2

RUN_DEPENDS=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		bash:${PORTSDIR}/shells/bash \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		transcode:${PORTSDIR}/multimedia/transcode

NO_BUILD=	yes
PLIST_FILES=	bin/mkxvcd

PORTDOCS=	AUTHORS Changelog README TODO

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${PREFIX}/bin/bash|' \
		${WRKSRC}/mkxvcd.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkxvcd.sh ${PREFIX}/bin/mkxvcd

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
