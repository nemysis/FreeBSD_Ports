# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/epiar/Makefile 316343 2013-04-23 10:47:02Z bapt $

PORTNAME=	epiar
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GH

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Space trading/exploring sim with RPG elements

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/LICENSE.music
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		ftgl:${PORTSDIR}/graphics/ftgl \
		xml2:${PORTSDIR}/textproc/libxml2 \
		physfs:${PORTSDIR}/devel/physfs

USE_GITHUB=	yes
GH_ACCOUNT=	knowknowledge
GH_PROJECT=	Epiar
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	44046e3

USES=		pkgconfig
USE_SDL=	image mixer sdl
USE_GL=		glu
USE_AUTOTOOLS=	aclocal automake autoheader autoconf
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

run-autotools:
	@${DO_NADA}

pre-configure:
	@${REINPLACE_CMD} -e 's|9.22|2.4|' ${WRKSRC}/configure.in
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
