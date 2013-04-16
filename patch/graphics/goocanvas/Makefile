# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD: head/graphics/goocanvas/Makefile 300896 2012-07-14 13:54:48Z beat $
#    $MCom: ports/graphics/goocanvas/Makefile,v 1.3 2008/02/27 16:19:11 ahze Exp $

PORTNAME=	goocanvas
PORTVERSION=	0.15
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Canvas widget for GTK+

USE_BZIP2=	yes
USES=		pathfix
USE_PKGCONFIG=	build
USE_GNOME=	gtk20 gdkpixbuf2 ltverhack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.in
.endif

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||g' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
