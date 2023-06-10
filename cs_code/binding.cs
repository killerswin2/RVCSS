using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Numerics;

namespace RV
{
    public class GameValue
    {
        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr CreateGameValue();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr CreateGameValueFloat(float value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr CreateGameValueInt(int value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr CreateGameValueBool(bool value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr CreateGameValueString(string value);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr CreateGameValueArray(IntPtr pointer, int length);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr CreateGameValueVector2(Vector2 vector);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr CreateGameValueVector3(Vector3 vector);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern void DeleteGameValue(IntPtr gameValuePointer);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr acctime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr action(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr actionids(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr actionkeys(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr actionkeysex(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr actionkeysimages(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr actionkeysnames(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr actionkeysnamesarray(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr actionname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr actionparams(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr activateaddons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr activatedaddons();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr activatekey(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr activetitleeffectparams(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr add3denconnection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr add3deneventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr add3denlayer(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addaction(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addbackpack(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addbackpackcargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addbackpackcargoglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addbackpackglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addbinocularitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addcamshake(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addcuratoraddons(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addcuratorcameraarea(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addcuratoreditableobjects(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addcuratoreditingarea(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addcuratorpoints(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addeditorobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addforce(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addforcegeneratorrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addgoggles(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addgroupicon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addhandgunitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addheadgear(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr additem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr additemcargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr additemcargoglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr additempool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr additemtobackpack(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr additemtouniform(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr additemtovest(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addlivestats(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmagazine(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmagazineammocargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmagazinecargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmagazinecargoglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmagazineglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmagazinepool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmagazines(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmagazineturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmenu(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmenuitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmissioneventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmpeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addmusiceventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addonfiles(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addownedmine(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addplayerscores(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addprimaryweaponitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addpublicvariableeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addrating(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addresources(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addscore(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addscoreside(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addsecondaryweaponitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addswitchableunit(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addteammember(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addtoremainscollector(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addtorque(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr adduniform(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr adduseractioneventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addvehicle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addvest(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addwaypoint(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweapon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweaponcargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweaponcargoglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweaponglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweaponitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweaponpool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweaponturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweaponwithattachmentscargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr addweaponwithattachmentscargoglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr admin(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr agent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr agents();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr agltoasl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr aimedattarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr aimpos(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr airdensitycurvertd();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr airdensityrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr airplanethrottle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr airportside(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr aisfinishheal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr alive(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr all3denentities();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allactivetitleeffects();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr alladdonsinfo();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allairports();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allcontrols(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allcurators();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allcutlayers();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr alldead();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr alldeadmen();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr alldiaryrecords(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr alldiarysubjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr alldisplays();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allenv3dsoundsources();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allgroups();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr alllods(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allmapmarkers();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allmines();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allmissionobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allobjects(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allow3dmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowcrewinimmobile(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowcuratorlogicignoreareas(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowdamage(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowdammage(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowedservice(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowfileoperations(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowfleeing(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowgetin(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowservice(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allowsprint(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allplayers();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allsimpleobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allsites();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allturrets(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allunits();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allunitsuav();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allusers();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr allvariables(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ambienttemperature();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ammo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ammoonpylon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr and(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animate(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animatebay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animatedoor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animatepylon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animatesource(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animationnames(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animationphase(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animationsourcephase(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr animationstate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr apertureparams();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr append(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr apply(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr armorypoints();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr arrayintersect(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr asin(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr asltoagl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr asltoatl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assert(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignascargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignascargoindex(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignascommander(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignasdriver(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignasgunner(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignasturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assigncurator(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedcommander(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assigneddriver(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedgroup(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedgunner(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assigneditems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedtarget(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedteam(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedvehicle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedvehiclerole(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignedvehicles(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assignteam(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr assigntoairport(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr atan(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr atan2(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr atg(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr atltoasl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr attachedobject(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr attachedobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr attachedto(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr attachobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr attachto(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr attackenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr awake(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr backpack(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr backpackcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr backpackcontainer(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr backpackitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr backpackmagazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr backpacks(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr backpackspacefor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr behaviour(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr benchmark();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr bezierinterpolation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr binocular(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr binocularitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr binocularmagazine(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr blufor();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr boundingbox(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr boundingboxreal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr boundingcenter(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr brakesdisabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr breakout(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr breakto(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr breakwith(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr briefingname();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr buildingexit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr buildingpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr buldozer_enableroaddiag(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr buldozer_isenabledroaddiag();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr buldozer_loadnewroads(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr buldozer_reloadopermap();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr buttonaction(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr buttonsetaction(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cadetmode();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr calculatepath(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr calculateplayervisibilitybyfriendly(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr call(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr callextension(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camcommand(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camcommit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camcommitprepared(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camcommitted(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camconstuctionsetparams(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camcreate(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camdestroy(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cameraeffect(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cameraeffectenablehud(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camerainterest(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cameraon();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cameraview();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campaignconfigfile();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreload(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreloaded(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparebank(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparedir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparedive(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparefocus(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparefov(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparefovrange(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparepos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparerelpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr campreparetarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsetbank(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsetdir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsetdive(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsetfocus(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsetfov(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsetfovrange(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsetpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsetrelpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camsettarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camtarget(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr camusenvg(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canadd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canadditemtobackpack(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canadditemtouniform(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canadditemtovest(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cancelsimpletaskdestination(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr candeployweapon(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canfire(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canmove(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canslingload(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canstand(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cansuspend();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cantriggerdynamicsimulation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canunloadincombat(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr canvehiclecargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr captive(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr captivenum(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cbchecked(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cbsetchecked(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ceil(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr channelenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cheatsenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr checkaifeature(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr checkvisibility(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr civilian();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr classname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clear3denattribute(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clear3deninventory(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearallitemsfrombackpack(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearbackpackcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearbackpackcargoglobal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearforcesrtd();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cleargroupicons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearitemcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearitemcargoglobal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearitempool();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearmagazinecargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearmagazinecargoglobal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearmagazinepool();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearoverlay(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearradio();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearweaponcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearweaponcargoglobal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clearweaponpool();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr clientowner();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr closedialog(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr closedisplay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr closeoverlay(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr collapseobjecttree(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr collect3denhistory(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr collectivertd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr collisiondisabledwith(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr combatbehaviour(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr combatmode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandartilleryfire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandchat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commander(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandfire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandfollow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandfsm(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandgetout(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandingmenu();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandmove(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandradio(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandstop(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandsuppressivefire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandtarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commandwatch(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr comment(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr commitoverlay(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr compatibleitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr compatiblemagazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr compile(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr compilefinal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr compilescript(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr completedfsm(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr composetext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configaccessor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configclasses(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configfile();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr confighierarchy(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr confignull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configof(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configproperties(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configsourceaddonlist(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configsourcemod(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr configsourcemodlist(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr confirmsensortarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr connectterminaltouav(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr connecttoserver(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr continuewith(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr controlnull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr controlsgroupctrl(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr conversationdisabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr copyfromclipboard();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr copytoclipboard(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr copywaypoints(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cos(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr count(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr countenemy(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr countfriendly(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr countside(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr counttype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr countunknown(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr create3dencomposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr create3denentity(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createagent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createcenter(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createdialog(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr creatediarylink(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr creatediaryrecord(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr creatediarysubject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createdisplay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr creategeardialog(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr creategroup(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createguardedpoint(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createhashmap();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createhashmapfromarray(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createlocation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createmarker(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createmarkerlocal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createmenu(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createmine(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createmissiondisplay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr creatempcampaigndisplay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createsimpleobject(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createsimpletask(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createsite(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createsoundsource(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createtask(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createteam(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createtrigger(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createunit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createvehicle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createvehiclecrew(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr createvehiclelocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr crew(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctaddheader(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctaddrow(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctclear(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctcursel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctfindheaderrows(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctfindrowheader(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctheadercontrols(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctheadercount(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctremoveheaders(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctremoverows(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlactivate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrladdeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlangle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlanimatemodel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlanimationphasemodel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlautoscrolldelay(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlautoscrollrewind(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlautoscrollspeed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlbackgroundcolor(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlchecked(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlclassname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlcommit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlcommitted(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlcreate(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrldelete(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlenable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlfade(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlfontheight(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlforegroundcolor(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlhtmlloaded(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlidc(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlidd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapanimadd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapanimclear(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapanimcommit(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapanimdone(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapcursor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapdir(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapmouseover(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapscale(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapscreentoworld(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapsetposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmapworldtoscreen(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmodel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmodeldirandup(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmodelscale(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlmouseposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlparent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlparentcontrolsgroup(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlremovealleventhandlers(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlremoveeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlscale(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlscrollvalues(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetactivecolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetangle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetautoscrolldelay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetautoscrollrewind(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetautoscrollspeed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetbackgroundcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetchecked(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetdisabledcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlseteventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfade(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfocus(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfont(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth1(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth1b(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth2(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth2b(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth3(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth3b(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth4(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth4b(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth5(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth5b(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth6(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfonth6b(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontheight(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontheighth1(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontheighth2(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontheighth3(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontheighth4(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontheighth5(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontheighth6(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontheightsecondary(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontp(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontpb(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetfontsecondary(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetforegroundcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetmodel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetmodeldirandup(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetmodelscale(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetmouseposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetpixelprecision(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetpositionh(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetpositionw(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetpositionx(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetpositiony(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetscale(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetscrollvalues(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetshadow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsetstructuredtext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettextcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettextcolorsecondary(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettextsecondary(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettextselection(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettooltip(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettooltipcolorbox(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettooltipcolorshade(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettooltipcolortext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlsettooltipmaxwidth(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlseturl(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlseturloverlaymode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlshadow(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlshow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlshown(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlstyle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrltext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrltextcolor(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrltextheight(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrltextsecondary(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrltextselection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrltextwidth(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrltooltip(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrltype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlurl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlurloverlaymode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrlvisible(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrowcontrols(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctrowcount(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctsetcursel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctsetdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctsetheadertemplate(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctsetrowtemplate(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctsetvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ctvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatoraddons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatorcamera();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatorcameraarea(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatorcameraareaceiling(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatorcoef(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatoreditableobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatoreditingarea(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatoreditingareatype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatormouseover();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatorpoints(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatorregisteredobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatorselected();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr curatorwaypointcost(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr current3denoperation();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentchannel();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentcommand(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentmagazine(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentmagazinedetail(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentmagazinedetailturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentmagazineturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentmuzzle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentnamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentpilot(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currenttask(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currenttasks(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentthrowable(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentvisionmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentwaypoint(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentweapon(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentweaponmode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentweaponturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr currentzeroing(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cursorobject();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cursortarget();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr customchat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr customradio(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr customwaypointposition();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cutfadeout(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cutobj(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cutrsc(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr cuttext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr damage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr date();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr datetonumber(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr daytime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deactivatekey(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr debriefingtext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr debugfsm(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr debuglog(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr decaygraphvalues(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deg(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr delete3denentities(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deleteat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletecenter(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletecollection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deleteeditorobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletegroup(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletegroupwhenempty(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deleteidentity(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletelocation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletemarker(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletemarkerlocal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deleterange(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deleteresources(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletesite(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletestatus(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deleteteam(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletevehicle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletevehiclecrew(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr deletewaypoint(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr detach(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr detectedmines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_activemissionfsms();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_activescripts();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_activesqfscripts();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_activesqsscripts();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_allmissioneventhandlers();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_captureframe(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_captureframetofile(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_captureslowframe(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_codeperformance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_deltatime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_drawmode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_dumpcalltracetolog();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_dumpscriptassembly(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_dumpterrainsynth();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_dynamicsimulationend(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_enable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_enabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_exportconfig(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_exportterrainsvg(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_fps();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_fpsmin();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_frameno();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_getterrainsegmentoffset(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_lightnewload(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_list(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_localized(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_log(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_logslowframe(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_mergeconfigfile(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_recordturretlimits(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_resetfsm();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_resetshapes();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_scope();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_setlightnew(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_stacktrace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_ticktime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diag_toggle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dialog();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diaryrecordnull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr diarysubjectexists(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr didjip();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr didjipowner(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr difficulty();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr difficultyenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr difficultyenabledrtd();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr difficultyoption(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr direction(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr directionstabilizationenabled(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr directsay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disableai(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disablebrakes(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disablecollisionwith(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disableconversation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disabledebriefingstats();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disablemapindicators(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disablenvgequipment(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disableremotesensors(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disableserialization();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disabletiequipment(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disableuavconnectability(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr disableuserinput(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displayaddeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displaychild(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displayctrl(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displaynull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displayparent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displayremovealleventhandlers(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displayremoveeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displayseteventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displayuniquename(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr displayupdate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dissolveteam(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr distance(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr distance2d(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr distancesqr(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr distributionregion();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr do(IntPtr leftGameValue, IntPtr rightGameValue);

[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr do3denaction(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr doartilleryfire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dofire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dofollow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dofsm(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dogetout(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr domove(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr doorphase(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dostop(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dosuppressivefire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dotarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dowatch(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawarrow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawellipse(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawicon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawicon3d(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawlaser(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawline(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawline3d(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawlink(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawlocation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawpolygon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawrectangle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drawtriangle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr driver(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr drop(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dynamicsimulationdistance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dynamicsimulationdistancecoef(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dynamicsimulationenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr dynamicsimulationsystemenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr east();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr echo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr edit3denmissionattributes(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr editobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr editorseteventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr effectivecommander(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr elevateperiscope(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr emptypositions(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableai(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableaifeature(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableaimprecision(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableattack(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableaudiofeature(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableautostartuprtd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableautotrimrtd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablecamshake(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablecaustics(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablechannel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablecollisionwith(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablecopilot(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enabledebriefingstats(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablediaglegend(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enabledirectionstabilization(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enabledynamicsimulation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enabledynamicsimulationsystem(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableenddialog();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableengineartillery(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableenvironment(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablefatigue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablegunlights(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableinfopanelcomponent(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableirlasers(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablemimics(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablepersonturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableradio(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablereload(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableropeattach(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablesatnormalondetail(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablesaving(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablesentences(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablesimulation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablesimulationglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablestamina(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablestressdamage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableteamswitch(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enabletraffic(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableuavconnectability(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableuavwaypoints(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablevehiclecargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enablevehiclesensor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enableweapondisassembly(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr endl();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr endloadingscreen();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr endmission(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr engineon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enginesisonrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enginespowerrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enginesrpmrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr enginestorquertd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr entities(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr environmentenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr environmentvolume();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr equipmentdisabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr estimatedendservertime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr estimatedtimeleft(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr evalobjectargument(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr everybackpack(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr everycontainer(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr exec(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr execeditorscript(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr execfsm(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr execvm(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr exit();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr exitwith(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr exp(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr expecteddestination(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr exportjipmessages(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr eyedirection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr eyepos(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr face(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr faction(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fadeenvironment(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fademusic(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr faderadio(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fadesound(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fadespeech(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr failmission(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fileexists(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fillweaponsfrompool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr find(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr findany(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr findcover(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr finddisplay(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr findeditorobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr findemptyposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr findemptypositionready(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr findif(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr findnearestenemy(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr finishmissioninit();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr finite(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fireattarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr firstbackpack(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr flag(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr flaganimationphase(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr flagowner(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr flagside(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr flagtexture(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr flatten(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fleeing(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr floor(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr flyinheight(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr flyinheightasl(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr focusedctrl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fog();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fogforecast();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fogparams();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forceadduniform(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forceatpositionrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forcecadetdifficulty(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forcedmap();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forceend();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forceflagtexture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forcefollowroad(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forcegeneratorrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forcemap(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forcerespawn(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forcespeed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forceunicode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forcewalk(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forceweaponfire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forceweatherchange();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr foreachmember(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr foreachmemberagent(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr foreachmemberteam(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr forgettarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr format(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr formation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr formationdirection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr formationleader(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr formationmembers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr formationposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr formationtask(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr formattext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr formleader(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr freeextension(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr freelook();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr from(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fromeditor(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fuel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr fullcrew(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gearidcammocount(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gearslotammocount(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gearslotdata(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gesturestate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denactionstate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denattribute(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3dencamera();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denconnections(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denentity(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denentityid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3dengrid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3deniconsvisible();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denlayerentities(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denlinesvisible();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denmissionattribute(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denmouseover();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr get3denselected(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getaimingcoef(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getallenv3dsoundcontrollers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getallenvsoundcontrollers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getallhitpointsdamage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getallownedmines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getallpylonsinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getallsoundcontrollers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getallunittraits(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getammocargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getanimaimprecision(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getanimspeedcoef(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getarray(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getartilleryammo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getartillerycomputersettings();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getartilleryeta(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getassetdlcinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getassignedcuratorlogic(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getassignedcuratorunit(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getattacktarget(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getaudiooptionvolumes();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getbackpackcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getbleedingremaining(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getburningvalue(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcalculateplayervisibilitybyfriendly();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcameraviewdirection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcargoindex(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcenterofmass(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getclientstate();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getclientstatenumber();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcompatiblepylonmagazines(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getconnecteduav(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getconnecteduavunit(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcontainermaxload(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcorpse(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcruisecontrol(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcursorobjectparams();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcustomaimcoef(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcustomsoundcontroller(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getcustomsoundcontrollercount(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdammage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdebriefingtext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdescription(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdirvisual(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdiverstate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdlcassetsusage();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdlcassetsusagebyname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdlcs(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getdlcusagetime(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr geteditorcamera(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr geteditormode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr geteditorobjectscope(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getelevationoffset();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getenginetargetrpmrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getenv3dsoundcontroller(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getenvsoundcontroller(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr geteventhandlerinfo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getfatigue(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getfieldmanualstartpage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getforcedflagtexture(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getforcedspeed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getfriend(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getfsmvariable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getfuelcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getgraphvalues(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getgroupicon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getgroupiconparams(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getgroupicons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gethidefrom(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gethit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gethitindex(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gethitpointdamage(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getitemcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getlighting();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getlightingat(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getloadedmodsinfo();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmagazinecargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmarkercolor(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmarkerpos(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmarkersize(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmarkertype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmass(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmissionconfig(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmissionconfigvalue(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmissiondlcs();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmissionlayerentities(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmissionlayers();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmissionpath(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmodelinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmouseposition();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getmusicplayedtime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getnumber(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectargument(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectchildren(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectdlc(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectfov(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectmaterials(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectproxy(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectscale(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjecttextures(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjecttype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getobjectviewdistance();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getopticsmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getordefault(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getordefaultcall(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getoxygenremaining(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getpersonuseddlcs(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getpilotcameradirection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getpilotcameraposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getpilotcamerarotation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getpilotcameratarget(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getpipviewdistance();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getplatenumber(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getplayerchannel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getplayerid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getplayerscores(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getplayeruid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getplayervonvolume(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getposasl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getposaslvisual(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getposaslw(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getposatl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getposatlvisual(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getposvisual(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getposworld(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getposworldvisual(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getpylonmagazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getreldir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getrelpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getremotesensorsdisabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getrepaircargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getresolution();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getroadinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getrotorbrakertd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getsensortargets(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getsensorthreats(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getshadowdistance();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getshotparents(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getslingload(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getsoundcontroller(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getsoundcontrollerresult(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getspeed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getstamina(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getstatvalue(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getsteamfriendsservers();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getsubtitleoptions();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getsuppression(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getterraingrid();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getterrainheight(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getterrainheightasl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getterraininfo();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gettext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gettextraw(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gettextureinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gettextwidth(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gettiparameters();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gettotaldlcusagetime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gettowparent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gettrimoffsetrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getturretlimits(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getturretopticsmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getunitfreefallinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getunitloadout(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getunittrait(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getunloadincombat(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getuserinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getusermfdtext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getusermfdvalue(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getvariable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getvehiclecargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getvehicletipars(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getvideooptions();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getweaponcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getweaponsway(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getwingsorientationrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getwingspositionrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr getwppos(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr glanceat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr globalchat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr globalradio(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr goggles(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr group(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupchat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupfromnetid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupiconselectable();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupiconsvisible();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupowner(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupradio(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groups(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupselectedunits(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr groupselectunit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr grpnull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gunner(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr gusts();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr halt();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr handgunitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr handgunmagazine(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr handgunweapon(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr handshit(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hashvalue(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hasinterface();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr haspilotcamera(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hasweapon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcallgroups(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcgroupparams(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcleader(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcremoveallgroups(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcremovegroup(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcselected(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcselectgroup(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcsetgroup(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcshowbar(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hcshownbar();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr headgear(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hidebody(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hideobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hideobjectglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hideselection(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hint(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hintc(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hintcadet(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hintsilent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hmd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hostmission(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr htmlload(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr hudmovementlevels();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr humidity();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr image(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr importallgroups(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr importance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr in(IntPtr leftGameValue, IntPtr rightGameValue);

[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inarea(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inareaarray(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr incapacitatedstate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr independent();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inflame(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inflamed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr infopanel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr infopanelcomponentenabled(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr infopanelcomponents(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr infopanels(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ingameuiseteventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inheritsfrom(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr initambientlife();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inpolygon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inputaction(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inputcontroller(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inputmouse(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inrangeofartillery(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr insert(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr inserteditorobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr insidebuilding(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr intersect(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr is3den();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr is3denmultiplayer();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr is3denpreview();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isabletobreathe(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isactionmenuvisible();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isagent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isaimprecisionenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isallowedcrewinimmobile(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isarray(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isautohoveron(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isautonomous(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isautostartupenabledrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isautotest();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isautotrimonrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isawake(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isbleeding(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isburning(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isclass(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr iscollisionlighton(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr iscopilotenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isdamageallowed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isdedicated();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isdlcavailable(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isengineon(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isequalref(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isequalto(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isequaltype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isequaltypeall(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isequaltypeany(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isequaltypearray(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isequaltypeparams(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isfilepatchingenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isfinal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isflashlighton(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isflatempty(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isforcedwalk(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isformationleader(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isgamefocused();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isgamepaused();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isgroupdeletedwhenempty(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ishidden(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isinremainscollector(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isinstructorfigureenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isirlaseron(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr iskeyactive(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr iskindof(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr islaseron(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr islighton(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr islocalized(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ismanualfire(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ismarkedforcollection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ismissionprofilenamespaceloaded();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ismultiplayer();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ismultiplayersolo();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isnil(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isnotequalref(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isnotequalto(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isnull(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isnumber(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isobjecthidden(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isobjectrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isonroad(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ispipenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isplayer(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isrealtime(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isremoteexecuted();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isremoteexecutedjip();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr issaving();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr issensortargetconfirmed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isserver();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isshowing3dicons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr issimpleobject(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr issprintallowed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isstaminaenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr issteammission();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr issteamoverlayenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isstreamfriendlyuienabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isstressdamageenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr istext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr istouchingground(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isturnedout(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr istuthintsenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isuavconnectable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isuavconnected(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isuicontext();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isuniformallowed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isvehiclecargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isvehicleradaron(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isvehiclesensorenabled(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr iswalking(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isweapondeployed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr isweaponrested(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr itemcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr items(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr itemswithmagazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr join(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr joinas(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr joinassilent(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr joinsilent(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr joinstring(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr kbadddatabase(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr kbadddatabasetargets(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr kbaddtopic(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr kbhastopic(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr kbreact(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr kbremovetopic(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr kbtell(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr kbwassaid(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr keyimage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr keyname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr keys(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr knowsabout(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr land(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr landat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr landresult(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr language();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lasertarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbadd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbclear(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbcolorright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbcursel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbdelete(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbisselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbpicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbpictureright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbselection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetcolorright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetcursel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetpicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetpicturecolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetpicturecolordisabled(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetpicturecolorselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetpictureright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetpicturerightcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetpicturerightcolordisabled(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetpicturerightcolorselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetselectcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetselectcolorright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsettext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsettextright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsettooltip(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsetvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsize(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsort(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsortby(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbsortbyvalue(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbtext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbtextright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbtooltip(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lbvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leader(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboarddeinit(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboardgetrows(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboardinit(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboardrequestrowsfriends(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboardrequestrowsglobal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboardrequestrowsglobalarounduser(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboardsrequestuploadscore(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboardsrequestuploadscorekeepbest(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leaderboardstate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr leavevehicle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr librarycredits();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr librarydisclaimers();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lifestate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lightattachobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lightdetachobject(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lightison(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lightnings();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr limitspeed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr linearconversion(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr linebreak();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lineintersects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lineintersectsobjs(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lineintersectssurfaces(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lineintersectswith(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr linkitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr list(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr listobjects(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr listremotetargets(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr listvehiclesensors(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ln(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbaddarray(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbaddcolumn(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbaddrow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbclear(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbcolorright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbcurselrow(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbdeletecolumn(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbdeleterow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbgetcolumnsposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbpicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbpictureright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetcolorright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetcolumnspos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetcurselrow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetpicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetpicturecolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetpicturecolorright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetpicturecolorselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetpicturecolorselectedright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetpictureright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsettext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsettextright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsettooltip(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsetvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsize(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsort(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsortby(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbsortbyvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbtext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbtextright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lnbvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr load(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadabs(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadbackpack(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadconfig(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadfile(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadgame();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadidentity(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadmagazine(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadoverlay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadstatus(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loaduniform(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr loadvest(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr local(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr localize(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr localnamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr locationnull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr locationposition(IntPtr rightGameValue);

        //[SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        //private static extern IntPtr lock(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockcamerato(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockcargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockdriver(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr locked(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockedcamerato(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockedcargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockeddriver(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockedinventory(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockedturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockidentity(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockinventory(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lockwp(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr logentities();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lognetwork(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lognetworkterminate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lookat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr lookatpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinecargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesallturrets(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesammo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesammocargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesammofull(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesdetail(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesdetailbackpack(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesdetailuniform(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesdetailvest(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazinesturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr magazineturretammo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr mapanimadd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr mapanimclear();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr mapanimcommit();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr mapanimdone();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr mapcenteroncamera(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr mapgridposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markasfinishedonsteam();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markeralpha(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markerbrush(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markerchannel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markercolor(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markerdir(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markerpolyline(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markerpos(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markershadow(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markershape(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markersize(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markertext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr markertype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr matrixmultiply(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr matrixtranspose(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr max(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr maxload(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr members(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuaction(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuadd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuchecked(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuclear(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menucollapse(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menudata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menudelete(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuenable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuenabled(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuexpand(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuhover(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menupicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusetaction(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusetcheck(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusetdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusetpicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusetshortcut(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusettext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuseturl(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusetvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menushortcut(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menushortcuttext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusize(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menusort(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menutext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuurl(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr menuvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr merge(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr min(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr mineactive(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr minedetectedby(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missiletarget(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missiletargetpos(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missionconfigfile();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missiondifficulty();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missionend();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missionname();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missionnamesource();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missionnamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missionprofilenamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missionstart();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr missionversion();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr mod(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr modeltoworld(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr modeltoworldvisual(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr modeltoworldvisualworld(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr modeltoworldworld(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr modparams(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moonintensity();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moonphase(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr morale(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr move(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr move3dencamera(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveinany(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveincargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveincommander(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveindriver(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveingunner(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveinturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveobjecttoend(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveout(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr movetime(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr moveto(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr movetocompleted(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr movetofailed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr musicvolume();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr name(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr namedproperties(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr namesound(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearentities(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearestbuilding(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearestlocation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearestlocations(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearestlocationwithdubbing(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearestmines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearestobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearestobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearestterrainobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearobjects(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearobjectsready(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearroads(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nearsupplies(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr neartargets(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr needreload(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr needservice(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr netid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr netobjnull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr newoverlay(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nextmenuitemindex(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nextweatherchange();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nil();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr nmenuitems(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr not(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr numberofenginesrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr numbertodate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr objectcurators(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr objectfromnetid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr objectparent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr objnull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr objstatus(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onbriefinggroup(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onbriefingnotes(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onbriefingplan(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onbriefingteamswitch(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr oncommandmodechanged(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ondoubleclick(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr oneachframe(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ongroupiconclick(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ongroupiconoverenter(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ongroupiconoverleave(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onhcgroupselectionchanged(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onmapsingleclick(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onplayerconnected(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onplayerdisconnected(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onpreloadfinished(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onpreloadstarted(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onshownewobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr onteamswitch(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr opencuratorinterface();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr opendlcpage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr opengps(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr openmap(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr opensteamapp(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr openyoutubevideo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr opfor();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr or(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ordergetin(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr overcast();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr overcastforecast();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr owner(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr param(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr parsenumber(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr parsesimplearray(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr parsetext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr parsingnamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr particlesquality();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr periscopeelevation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pi();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pickweaponpool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pitch(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pixelgrid();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pixelgridbase();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pixelgridnouiscale();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pixelh();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pixelw();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playableslotsnumber(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playableunits();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playaction(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playactionnow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr player();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playerrespawntime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playerside();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playersnumber(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playgesture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playmission(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playmove(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playmovenow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playmusic(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playscriptedmission(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playsound(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playsound3d(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr playsoundui(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pose(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr position(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr positioncameratoworld(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr posscreentoworld(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr posworldtoscreen(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ppeffectadjust(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ppeffectcommit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ppeffectcommitted(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ppeffectcreate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ppeffectdestroy(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ppeffectenable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ppeffectenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ppeffectforceinnvg(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr precision(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr preloadcamera(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr preloadobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr preloadsound(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr preloadtitleobj(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr preloadtitlersc(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr preprocessfile(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr preprocessfilelinenumbers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr primaryweapon(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr primaryweaponitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr primaryweaponmagazine(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr priority(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr processdiarylink(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr productversion();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr profilename();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr profilenamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr profilenamesteam();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr progressloadingscreen(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr progressposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr progresssetposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr publicvariable(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr publicvariableclient(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr publicvariableserver(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pushback(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr pushbackunique(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr putweaponpool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr queryitemspool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr querymagazinepool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr queryweaponpool(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rad(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr radiochanneladd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr radiochannelcreate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr radiochannelinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr radiochannelremove(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr radiochannelsetcallsign(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr radiochannelsetlabel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr radioenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr radiovolume();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rain();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rainbow();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rainparams();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr random(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rank(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rankid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rating(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rectangular(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr regexfind(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr regexmatch(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr regexreplace(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr registeredtasks(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr registertask(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr reload(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr reloadenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr remotecontrol(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr remoteexec(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr remoteexeccall(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr remoteexecutedowner();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr remove3denconnection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr remove3deneventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr remove3denlayer(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeaction(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeall3deneventhandlers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallactions(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallassigneditems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallbinocularitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallcontainers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallcuratoraddons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallcuratorcameraareas(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallcuratoreditingareas(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removealleventhandlers(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallhandgunitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallitemswithmagazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallmissioneventhandlers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallmpeventhandlers(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallmusiceventhandlers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallownedmines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallprimaryweaponitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallsecondaryweaponitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removealluseractioneventhandlers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeallweapons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removebackpack(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removebackpackglobal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removebinocularitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removecuratoraddons(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removecuratorcameraarea(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removecuratoreditableobjects(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removecuratoreditingarea(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removediaryrecord(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removediarysubject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removedrawicon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removedrawlinks(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removefromremainscollector(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removegoggles(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removegroupicon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removehandgunitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeheadgear(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeitemfrombackpack(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeitemfromuniform(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeitemfromvest(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeitems(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removemagazine(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removemagazineglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removemagazines(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removemagazinesturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removemagazineturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removemenuitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removemissioneventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removempeventhandler(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removemusiceventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeownedmine(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeprimaryweaponitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removesecondaryweaponitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removesimpletask(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeswitchableunit(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeteammember(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeuniform(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeuseractioneventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removevest(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeweapon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeweaponattachmentcargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeweaponcargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeweaponglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr removeweaponturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr reportremotetarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr requiredversion(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr resetcamshake();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr resetsubgroupdirection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr resistance();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr resize(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr resources(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr respawnvehicle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr restarteditorcamera(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr reveal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr revealmine(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr reverse(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr reversedmousey();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr roadat(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr roadsconnectedto(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr roledescription(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropeattachedobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropeattachedto(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropeattachenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropeattachto(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropecreate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropecut(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropedestroy(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropedetach(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropeendposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropelength(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropes(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropesattachedto(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropesegments(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropeunwind(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr ropeunwound(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rotorsforcesrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr rotorsrpmrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr round(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr runinitscript();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr safezoneh();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr safezonew();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr safezonewabs();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr safezonex();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr safezonexabs();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr safezoney();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr save3deninventory(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr savegame();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr saveidentity(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr savejoysticks();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr savemissionprofilenamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr saveoverlay(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr saveprofilenamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr savestatus(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr savevar(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr savingenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr say(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr say2d(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr say3d(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr scopename(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr score(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr scoreside(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr screenshot(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr screentoworld(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr scriptdone(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr scriptname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr scriptnull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr scudstate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr secondaryweapon(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr secondaryweaponitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr secondaryweaponmagazine(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr select(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectbestplaces(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectdiarysubject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectededitorobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selecteditorobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectionnames(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectionposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectionvectordirandup(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectleader(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectmax(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectmin(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectnoplayer();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectplayer(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectrandom(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectrandomweighted(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectweapon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr selectweaponturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sendaumessage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sendsimplecommand(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sendtask(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sendtaskresult(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sendudpmessage(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sentencesenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr servercommand(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr servercommandavailable(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr servercommandexecutable(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr servername();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr servernamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr servertime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denattribute(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denattributes(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3dengrid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3deniconsvisible(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denlayer(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denlinesvisible(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denlogictype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denmissionattribute(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denmissionattributes(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denmodelsvisible(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denobjecttype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr set3denselected(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setacctime(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setactualcollectivertd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setairplanethrottle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setairportside(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setammo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setammocargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setammoonpylon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setanimspeedcoef(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setaperture(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setaperturenew(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setarmorypoints(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setattributes(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setautonomous(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setbehaviour(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setbehaviourstrong(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setbleedingremaining(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setbrakesrtd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcamerainterest(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcamshakedefparams(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcamshakeparams(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcamuseti(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcaptive(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcenterofmass(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcollisionlight(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcombatbehaviour(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcombatmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcompassoscillation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setconvoyseparation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcruisecontrol(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcuratorcameraareaceiling(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcuratorcoef(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcuratoreditingareatype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcuratorwaypointcost(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcurrentchannel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcurrenttask(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcurrentwaypoint(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcustomaimcoef(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcustommissiondata(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcustomsoundcontroller(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setcustomweightrtd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdamage(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdammage(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdebriefingtext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdefaultcamera(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdestination(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdetailmapblendpars(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdiaryrecordtext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdiarysubjectpicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdirection(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdrawicon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdriveonpath(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdropinterval(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdynamicsimulationdistance(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setdynamicsimulationdistancecoef(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr seteditormode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr seteditorobjectscope(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr seteffectcondition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr seteffectivecommander(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setenginerpmrtd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setface(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfaceanimation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfatigue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfeaturetype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setflaganimationphase(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setflagowner(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setflagside(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setflagtexture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfog(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setforcegeneratorrtd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setformation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setformationtask(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setformdir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfriend(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfromeditor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfsmvariable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfuel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setfuelcargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setgroupicon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setgroupiconparams(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setgroupiconsselectable(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setgroupiconsvisible(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setgroupid(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setgroupidglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setgroupowner(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setgusts(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sethidebehind(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sethit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sethitindex(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sethitpointdamage(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sethorizonparallaxcoef(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sethudmovementlevels(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sethumidity(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setidentity(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setimportance(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setinfopanel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setleader(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightambient(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightattenuation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightbrightness(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightconepars(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightdaylight(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightflaremaxdistance(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightflaresize(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightintensity(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightnings(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightuseflare(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlightvolumeshape(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setlocalwindparams(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmagazineturretammo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkeralpha(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkeralphalocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkerbrush(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkerbrushlocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkercolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkercolorlocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkerdir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkerdirlocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkerpolyline(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkerpolylinelocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkerpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkerposlocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkershadow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkershadowlocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkershape(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkershapelocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkersize(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkersizelocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkertext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkertextlocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkertype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmarkertypelocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmass(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmaxload(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmimic(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmissiletarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmissiletargetpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmouseposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmusiceffect(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setmusiceventhandler(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setname(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setnamesound(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setobjectarguments(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setobjectmaterial(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setobjectmaterialglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setobjectproxy(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setobjectscale(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setobjecttexture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setobjecttextureglobal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setobjectviewdistance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setopticsmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setovercast(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setowner(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setoxygenremaining(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setparticlecircle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setparticleclass(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setparticlefire(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setparticleparams(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setparticlerandom(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpilotcameradirection(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpilotcamerarotation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpilotcameratarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpilotlight(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpipeffect(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpipviewdistance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpitch(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setplatenumber(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setplayable(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setplayerrespawntime(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setplayervonvolume(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setposasl(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setposasl2(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setposaslw(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setposatl(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setposworld(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpylonloadout(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setpylonspriority(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setradiomsg(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setrain(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setrainbow(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setrandomlip(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setrank(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setrectangular(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setrepaircargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setrotorbrakertd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setshadowdistance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setshotparents(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setside(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsimpletaskalwaysvisible(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsimpletaskcustomdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsimpletaskdescription(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsimpletaskdestination(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsimpletasktarget(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsimpletasktype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsimulweatherlayers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsize(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setskill(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setslingload(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsoundeffect(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setspeaker(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setspeech(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setspeedmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setstamina(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setstaminascheme(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setstatvalue(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsuppression(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setsystemofunits(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settargetage(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settaskmarkeroffset(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settaskresult(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settaskstate(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setterraingrid(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setterrainheight(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settimemultiplier(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settiparameter(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settitleeffect(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settowparent(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settrafficdensity(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settrafficdistance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settrafficgap(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settrafficspeed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settriggeractivation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settriggerarea(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settriggerinterval(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settriggerstatements(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settriggertext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settriggertimeout(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settriggertype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setturretlimits(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setturretopticsmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr settype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunconscious(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunitability(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunitcombatmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunitfreefallheight(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunitloadout(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunitpos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunitposweak(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunitrank(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunitrecoilcoefficient(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunittrait(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setunloadincombat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setuseractiontext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setusermfdtext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setusermfdvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvariable(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvectordir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvectordirandup(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvectorup(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehicleammo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehicleammodef(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehiclearmor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehiclecargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehicleid(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehiclelock(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehicleposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehicleradar(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehiclereceiveremotetargets(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehiclereportownposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehiclereportremotetargets(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehicletipars(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvehiclevarname(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvelocity(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvelocitymodelspace(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvelocitytransformation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setviewdistance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setvisibleiftreecollapsed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwantedrpmrtd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaves(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointbehaviour(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointcombatmode(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointcompletionradius(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointdescription(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointforcebehaviour(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointformation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointhouseposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointloiteraltitude(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointloiterradius(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointloitertype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointname(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointscript(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointspeed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointstatements(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointtimeout(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointtype(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwaypointvisible(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setweaponreloadingtime(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setweaponzeroing(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwind(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwinddir(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwindforce(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwindstr(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwingforcescalertd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr setwppos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr show3dicons(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showchat(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showcinemaborder(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showcommandingmenu(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showcompass(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showcuratorcompass(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showgps(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showhud(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showlegend(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showmap(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownartillerycomputer();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownchat();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showncompass();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showncuratorcompass();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showneweditorobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showngps();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownhud();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownmap();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownpad();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownradio();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownscoretable();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownsubtitles();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownuavfeed();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownwarrant();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr shownwatch();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showpad(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showradio(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showscoretable(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showsubtitles(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showuavfeed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showwarrant(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showwatch(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showwaypoint(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr showwaypoints(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr side(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sideambientlife();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sidechat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sideempty();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sideenemy();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sidefriendly();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sidelogic();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sideradio(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sideunknown();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr simpletasks(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr simulationenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr simulclouddensity(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr simulcloudocclusion(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr simulinclouds(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr simulweathersync();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sin(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr size(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sizeOf(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr skill(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr skillfinal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr skiptime(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sleep(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sliderposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sliderrange(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr slidersetposition(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr slidersetrange(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr slidersetspeed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sliderspeed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr slingloadassistantshown();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr soldiermagazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr someammo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sort(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr soundvolume();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr spawn(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr speaker(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr speechvolume();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr speed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr speedmode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr splitstring(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sqrt(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr squadparams(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr stance(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr startloadingscreen(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr step(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr stop(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr stopenginertd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr stopped(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr str(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr sunormoon();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr supportinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr suppressfor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr surfaceiswater(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr surfacenormal(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr surfacetexture(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr surfacetype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr swimindepth(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr switchableunits();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr switchaction(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr switchcamera(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr switchgesture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr switchlight(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr switchmove(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr synchronizedobjects(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr synchronizedtriggers(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr synchronizedwaypoints(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr synchronizeobjectsadd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr synchronizeobjectsremove(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr synchronizetrigger(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr synchronizewaypoint(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr systemchat(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr systemofunits();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr systemtime();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr systemtimeutc();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tan(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr targetknowledge(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr targets(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr targetsaggregate(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr targetsquery(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskalwaysvisible(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskchildren(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskcompleted(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskcustomdata(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskdescription(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskdestination(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskhint(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskmarkeroffset(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tasknull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskparent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskresult(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr taskstate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tasktype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr teammember(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr teammembernull();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr teamname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr teams();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr teamswitch();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr teamswitchenabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr teamtype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr terminate(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr terrainintersect(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr terrainintersectasl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr terrainintersectatasl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr text(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr textlog(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr textlogformat(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tg(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr timemultiplier();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr titlecut(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr titlefadeout(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr titleobj(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr titlersc(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr titletext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr to(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr toarray(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tofixed(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tolower(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr toloweransi(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tostring(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr toupper(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr toupperansi(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggeractivated(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggeractivation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggerammo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggerarea(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggerattachedvehicle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggerattachobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggerattachvehicle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggerdynamicsimulation(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggerinterval(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggerstatements(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggertext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggertimeout(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggertimeoutcurrent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr triggertype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr trim(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr turretlocal(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr turretowner(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr turretunit(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvadd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvclear(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvcollapse(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvcollapseall(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvcount(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvcursel(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvdelete(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvexpand(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvexpandall(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvisselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvpicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvpictureright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvselection(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetcursel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetdata(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetpicture(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetpicturecolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetpicturecolordisabled(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetpicturecolorselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetpictureright(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetpicturerightcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetpicturerightcolordisabled(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetpicturerightcolorselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetselectcolor(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetselected(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsettext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsettooltip(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsetvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsort(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsortall(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsortbyvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvsortbyvalueall(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvtext(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvtooltip(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr tvvalue(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr type(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr typename(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr typeOf(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr uavcontrol(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr uinamespace();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr uisleep(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unassigncurator(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unassignitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unassignteam(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unassignvehicle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr underwater(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr uniform(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr uniformcontainer(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr uniformitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr uniformmagazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr uniqueunititems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitaddons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitaimposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitaimpositionvisual(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitbackpack(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitcombatmode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitisuav(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitpos(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitready(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitrecoilcoefficient(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr units(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitsbelowheight(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unitturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unlinkitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unlockachievement(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr unregistertask(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr updatedrawicon(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr updatemenuitem(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr updateobjecttree(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr useaiopermapobstructiontest(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr useaisteeringcomponent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr useaudiotimeformoves(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr userinputdisabled();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr values(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectoradd(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectorcos(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectorcrossproduct(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectordiff(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectordir(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectordirvisual(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectordistance(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectordistancesqr(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectordotproduct(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectorfromto(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectorlinearconversion(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectormagnitude(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectormagnitudesqr(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectormodeltoworld(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectormodeltoworldvisual(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectormultiply(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectornormalized(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectorup(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectorupvisual(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectorworldtomodel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vectorworldtomodelvisual(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehicle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehiclecargoenabled(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehiclechat(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehiclemoveinfo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehicleradio(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehiclereceiveremotetargets(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehiclereportownposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehiclereportremotetargets(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehicles();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vehiclevarname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr velocity(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr velocitymodelspace(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr verifysignature(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vest(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vestcontainer(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vestitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr vestmagazines(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr viewdistance();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr visiblecompass();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr visiblegps();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr visiblemap();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr visibleposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr visiblepositionasl(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr visiblescoretable();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr visiblewatch();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waituntil(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waves();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointattachedobject(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointattachedvehicle(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointattachobject(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointattachvehicle(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointbehaviour(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointcombatmode(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointcompletionradius(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointdescription(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointforcebehaviour(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointformation(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointhouseposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointloiteraltitude(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointloiterradius(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointloitertype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointname(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointposition(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypoints(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointscript(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointsenableduav(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointshow(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointspeed(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointstatements(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointtimeout(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointtimeoutcurrent(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointtype(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr waypointvisible(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponaccessories(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponaccessoriescargo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponcargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weapondirection(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponinertia(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponlowered(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponreloadingtime(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weapons(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponsinfo(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponsitems(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponsitemscargo(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponstate(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weaponsturret(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr weightrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr west();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr wfsidetext(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr wind();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr winddir();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr windrtd();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr windstr();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr wingsforcesrtd(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr with(IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr worldname();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr worldsize();

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr worldtomodel(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr worldtomodelvisual(IntPtr leftGameValue, IntPtr rightGameValue);

        [SuppressUnmanagedCodeSecurity, DllImport("rvcss_x64")]
        private static extern IntPtr worldtoscreen(IntPtr rightGameValue);





        private readonly IntPtr _internalGameValue;
        public GameValue()
        {
            _internalGameValue = CreateGameValue();
        }

        public GameValue(float value)
        {
            _internalGameValue = CreateGameValueFloat(value);
        }

        public GameValue(int value)
        {
            _internalGameValue = CreateGameValueInt(value);
        }

        public GameValue(bool value)
        {
            _internalGameValue = CreateGameValueBool(value);
        }

        private GameValue(string value)
        {
            _internalGameValue = CreateGameValueString(value);
        }

        public GameValue(GameValue array, int length)
        {
            _internalGameValue = CreateGameValueArray(array._internalGameValue, length);
        }

        private GameValue(IntPtr array, int length)
        {
            _internalGameValue = CreateGameValueArray(array, length);
        }

        private GameValue(Vector2 value)
        {
            _internalGameValue = CreateGameValueVector2(value); ;
        }

        private GameValue(Vector3 value)
        {
            _internalGameValue = CreateGameValueVector3(value); ;
        }

        private GameValue(IntPtr gamePointer)
        {
            _internalGameValue = gamePointer;
        }

        ~GameValue()
        {
            DeleteGameValue(_internalGameValue);
        }
    }