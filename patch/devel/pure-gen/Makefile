# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/devel/pure-gen/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	pure-gen
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	C interface generator for the Pure language

LICENSE=	BSD

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-language-c>=0.3.2:${PORTSDIR}/devel/hs-language-c

CC=		gcc

USES=		pure:ffi

MAN1=		pure-gen.1

PLIST_FILES=	bin/${PORTNAME} \
		lib/pure-gen/dump-ast
PLIST_DIRS=	lib/pure-gen

PORTDOCS=	README README.dump-ast
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
