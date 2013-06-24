# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	pcmanfm-qt
PORTVERSION=	0.1.0
CATEGORIES=	x11-fm
MASTER_SITES=	SF/pcmanfm/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/PCManFM-Qt%20%28Qt%20port%20of%20PCManFM%20%2B%20libfm%29/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	nemysis@gmx.ch
COMMENT=	PCManFM Qt File Manager

LICENSE=	GPLv2

LIB_DEPENDS=	fm-gtk.4:${PORTSDIR}/x11/libfm

USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_GNOME=	glib20 gvfs
USE_XORG=	x11
USE_QT4=	corelib dbus gui uic moc_build qmake_build rcc_build linguist
USE_LDCONFIG=	yes

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
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/libfm-qt/CMakeLists.txt

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|install(FILES $${QM_FILES}|#install(FILES $${QM_FILES}|' \
		${WRKSRC}/libfm-qt/CMakeLists.txt ${WRKSRC}/pcmanfm/CMakeLists.txt
.endif

.include <bsd.port.mk>
