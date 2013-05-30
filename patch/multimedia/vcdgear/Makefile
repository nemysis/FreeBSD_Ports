# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD: head/multimedia/vcdgear/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	vcdgear
PORTVERSION=	1.6d
CATEGORIES=	multimedia
MASTER_SITES=	http://www.vcdgear.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to convert VCDs from cue/bin format to mpeg

ONLY_FOR_ARCHS=	alpha i386 amd64

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	faq.txt manual.txt whatsnew.txt

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == amd64
DISTNAME=	${PORTNAME}16d_i386_freebsd42
.elif ${ARCH} == alpha
DISTNAME=	${PORTNAME}16d_alpha_freebsd41
.endif

NO_BUILD=	true
WRKSRC=		${WRKDIR}/vcdgear16

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear16_static ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
