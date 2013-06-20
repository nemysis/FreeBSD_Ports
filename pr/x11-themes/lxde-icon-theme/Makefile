# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD: head/x11-themes/lxde-icon-theme/Makefile 321199 2013-06-18 15:55:34Z kmoore $

PORTNAME=	lxde-icon-theme
PORTVERSION=	0.5.0
CATEGORIES=	x11-themes
MASTER_SITES=	SF/lxde/LXDE%20Icon%20Theme/lxde-icon-theme-${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	LXDE Icon Theme

LICENSE=	GPLv3

USE_BZIP2=	YES
USES=		iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

DATADIR=	${PREFIX}/share/lxde
INSTALLS_ICONS=	YES

PORTDOCS=	AUTHORS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|cp -raf --no-preserve=ownership|cp -RpPf|' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
