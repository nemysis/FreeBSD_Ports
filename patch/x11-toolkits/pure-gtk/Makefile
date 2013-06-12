# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/x11-toolkits/pure-gtk/Makefile 300897 2012-07-14 14:29:18Z beat $

PORTNAME=	pure-gtk
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	x11-toolkits
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Set of Pure language bindings for GTK+

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USES=		pure:ffi
USE_GNOME=	glib20 gtk20 atk pango

PORTDOCS=	README

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
