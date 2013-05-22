# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD: head/deskutils/rubrica/Makefile 315433 2013-03-28 03:28:30Z eadler $

PORTNAME=	rubrica
PORTVERSION=	2.0.12
CATEGORIES=	deskutils gnome
MASTER_SITES=	BERLIOS
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Addressbook for the GNOME 2 desktop

LICENSE=	GPLv3

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

FETCH_ARGS?=	-Fpr
USE_BZIP2=	yes
USES=		desktop-file-utils pathfix
USE_GNOME=	gconf2 gnomeprefix libglade2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

GCONF_SCHEMAS=	rubrica2.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CREDITS ChangeLog

DOCSRCDIR2=	${WRKSRC}/doc/reference/html
DOCSDIR2=	${DOCSDIR}/doc/libRAL
DOC_FILES2=	*.*

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g|-Wall|g ; \
		 s|-Wmissing-prototypes -g|-Wmissing-prototypes|g'
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|_Modifica|_Edit|' \
		-e 's|A_iuto|_Help|' \
		${WRKSRC}/interface/MainWindow.glade

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||g' ${WRKSRC}/Makefile.in
.endif

post-install:
	@${LN} -sf ${LOCALBASE}/share/icons/gnome \
		${PREFIX}/share/pixmaps/rubrica2/22x22/hicolor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
