# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/devel/pure-stldict/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	pure-stldict
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure interface to C++ STL map/unordered_map

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

USES=		pure

USE_GCC=	4.6+
CXX=		g++${GCC_DEFAULT_V}
CXXFLAGS+=	-std=c++0x -DHAVE_STD_IS_PERMUTATION

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
