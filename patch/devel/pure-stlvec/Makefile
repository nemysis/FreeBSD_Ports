# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/devel/pure-stlvec/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	pure-stlvec
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure interface to C++ STL vector

LICENSE=	BSD

USES=		pure

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PROD_FLAGS =.*|PROD_FLAGS = $$(CPPFLAGS) $$(CFLAGS) $$(LDFLAGS)|' \
		${WRKSRC}/Makefile

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
