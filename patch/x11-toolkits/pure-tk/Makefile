# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/x11-toolkits/pure-tk/Makefile 318162 2013-05-14 14:16:52Z gahr $

PORTNAME=	pure-tk
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits
#MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Basic interface between Pure and Tcl/Tk

LICENSE=	BSD

USES=		pure
USE_TK=		86+
SHORT_TCL_VER=	${TCL_VER:S/8./8/}

MAKE_ARGS+=	tclvers=${TCL_VER}

PLIST_FILES=	lib/pure/gnocl.pure \
		lib/pure/tk.so \
		lib/pure/tk.pure

post-patch:
	${REINPLACE_CMD} \
		-e "s|/usr/include|${LOCALBASE}/include|g" \
		-e "s|-ltcl\$$(tclvers)|-ltcl${SHORT_TCL_VER}|" \
		-e "s|-ltk\$$(tclvers)|-ltk${SHORT_TCL_VER}|" \
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
