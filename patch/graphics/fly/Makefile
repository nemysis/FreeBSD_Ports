# Created by: Juergen Unger <j.unger@choin.net>
# $FreeBSD: head/graphics/fly/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	fly
PORTVERSION=	2.0.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://fossies.org/unix/www/ \
		http://martin.gleeson.com/fly/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple drawing language to generate GIFs on the fly

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/fly

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include fly.c -o fly \
		-L${LOCALBASE}/lib -lgd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
