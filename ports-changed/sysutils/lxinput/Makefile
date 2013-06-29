# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD: head/sysutils/lxinput/Makefile 321342 2013-06-19 23:51:05Z wen $

PORTNAME=	lxinput
PORTVERSION=	0.3.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXInput%20%28Kbd%20and%20amp_%20mouse%20config%29/LXInput%200.3.2/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Keyboard and mouse config tool from the LXDE project

USES=		iconv desktop-file-utils
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

MAN1=		lxinput.1

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
