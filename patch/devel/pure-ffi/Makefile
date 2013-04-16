# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/devel/pure-ffi/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	pure-ffi
PORTVERSION=	0.13
CATEGORIES=	devel
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to libffi

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS+=	ffi:${PORTSDIR}/devel/libffi

USES=	pure

PLIST_FILES=	lib/pure/ffi.pure \
		lib/pure/ffi.so

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
