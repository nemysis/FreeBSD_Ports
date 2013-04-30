# Created by: John Reynolds <johnjen@reynoldsnet.org>
# $FreeBSD: head/graphics/imageindex/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	imageindex
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.edwinh.org/imageindex/release/ \
		http://www.reynoldsnet.org/imageindex/release/

MAINTAINER=	johnjen@reynoldsnet.org
COMMENT=	Digital photo gallery tool

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		p5-Image-Info>=0:${PORTSDIR}/graphics/p5-Image-Info
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_PERL5_RUN=	yes
MAKE_ARGS+=	PERLPATH=${PERL}

PLIST_FILES=	bin/imageindex bin/autocaption
PORTDOCS=	README

MAN1=	imageindex.1

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
